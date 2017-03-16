""" Code competition solution wrapper

:Source: https://github.com/iki/codejam-seed

Usage
=====

* import:

    .. python::

        from coderun import *

* main execution:

    .. python::

        if __name__=='__main__':
            main(solve, parse, format, precompile=[])

    .. python::

        main(solve)

* doctest:

    .. this is sample only, do not run doctest on this module,

    .. python::

        >>> test('arg1', 'argn', kwarg1='kwarg1', kwargn='kwargn')
        result via format()

    .. python::

        >>> test('arg1', 'arg2', kwarg1='kwarg1', kwargn='kwargn',
        ...    testlabel = "sample")
        result via format()

    .. python::

        >>> test(
        ...    testlabel = "sample (parse)",
        ...    testinput = '''first line
        ... second line
        ... third line
        ... '''))
        result via format()

    .. python::

        >>> n, k = 500, 16
        >>> test(ring_graph(n, cyclic_distribution(k)),
        ...   testresult = range(k) + range(k-2, -1, -1),
        ...   testlabel = "ring of %d nodes with cyclic distribution of %d values" % (n,k))
"""
__docformat__ = 'restructuredtext en'
__all__ = ['main', 'test', 'log',
           'expressions', 'tuples', 'n_items', 'words', 'numbers', 'lines']

import sys, itertools

### logger

class logproxy:
    exception = error = warn = warning = info = str # do nothing
    debug = None

log = logproxy()            #  exported log proxy

### testing

def test(*args, **kwargs):
    """ doctest shortcut to test results of solve()

          * solve() parameters:

            - by default \*args and \*\*kwargs are used (except test related kwargs lower)
            - alternatively, testfile kwarg may be used as input stream for parse()
            - alternatively, testinput kwarg may be used as input string for parse()

          * result testing:

            - by default the output of `print format(stdout, solve())` is compared by doctest
            - alternatively, testresult kwarg may be used for testing large or special results
              using `(assert testresult == solve())`

          * test related kwargs are not passed to solve():

            - testfile      .. input stream for parse()
            - testinput     .. input string for parse()
            - testlabel     .. log label before test
            - testresult    .. assert equal to result of solve()
    """
    expected  = kwargs.pop('testresult', test) # expected==test => no assertion
    label     = kwargs.pop('testlabel',  None)
    infile    = kwargs.pop('testfile',   None)
    if 'testinput' in kwargs:
        from cStringIO import StringIO
        infile = StringIO(kwargs.pop('testinput'))

    if label: log.info('TEST: %s' % label)

    if infile:
        result = solve(*parse(infile))
    else:
        result = solve(*args, **kwargs)

    if expected == test: # expected==test => no assertion
        print format(result)
    elif expected != result:
        raise AssertionError, result


### time measurement

def timed(func, format='TIME: %(label)s: %(time)g [sec]: %(status)s',
    timer=None, **formatargs):
    """ decorates func() by measuring execution time
    """
    if timer is None:
        import time
        if sys.platform == "win32":
            timer = time.clock   # On Windows, the best timer is time.clock()
        else:
            timer = time.time    # On most other platforms the best timer is time.time()

    if not 'label' in formatargs:
        formatargs['label'] = getattr(func, '__name__', str(func))

    def timedfunc(*args, **kwargs):
        t0 = timer()

        try:
            r = func(*args, **kwargs)
        except:
            formatargs.update(time = timer()-t0, status=sys.exc_info()[0].__name__)
            log.info(format % formatargs)
            raise

        formatargs.update(time = timer()-t0, status='OK')
        log.info(format % formatargs)
        return r

    try:
        timedfunc.__name__ = func.__name__
    except:
        pass

    return timedfunc


### parsers

def expressions(stream):
    """ iterator over evaluated python expression per non-empty line
    """
    return (eval(line) for line in stream if line.strip())

def tuples(it, count):
    """ iterator over tuples of items from parent iterator
    """
    n = iter(it).next
    j = (None,) * count
    while True:
        yield tuple([n() for i in j])

def n_items(it, items=None, convertor=iter, **convertorargs):
    """ iterator over first items from convertor(it, **convertorargs)
        if items is None, it is read from iter(it)
    """
    if items is None:
        items = int(iter(it).next())
        if log.debug: log.debug('number of items: %d' % items)
    return itertools.islice(convertor(it, **convertorargs), items)

chunksize = 256 * 1024
max_chunksize_stdin = 16 * 1024

def words(stream, chunksize=chunksize, sep=None):
    """ iterator over words in input stream
    """
    buf = []
    orphan = ''

    if stream is sys.stdin:
        chunksize = min(chunksize, max_chunksize_stdin)

    while True:
        if buf:
            yield buf.pop(0)
        else:
            data = orphan + stream.read(chunksize)
            buf = data.split(sep)

            if not buf:
                return

            last = buf[-1]
            if data.endswith(last) and last != orphan:
                orphan = last
                del buf[-1:]

def numbers(stream, chunksize=chunksize):
    """ iterator over numbers in input stream
    """
    return itertools.imap(int, words(stream, chunksize))

def lines(stream, chunksize=chunksize):
    """ iterator over lines in input stream
    """
    return words(stream, '\n', chunksize)



### exec

def run(fi, fo=None):
    """ runs fo.write(format(solve(\*parse(fi))),
        or skips format if fo is None and returns result
    """
    if fo is None:
        return solve(*parse(fi))
    else:
        return fo.write(format(solve(*parse(fi))))

def main(solve, parse=expressions, format=str, log='', precompile=None,
    logformat='%(asctime)s %(levelname)7s: %(message)s', version=''):
    """ main execution

          * initializes logging
          * parses command line arguments
          * optionally adds timer to solve()
          * optionally precompiles solve+parse+format and functions called within
            (default if psyco available)
          * sets module global solve, parse, format, log, debug
          * call run() on stdin (default) or on filemask arguments,
            or execute doctest on solution module (__main__) if requested
    """
    __globals = globals()

    if not 'logging' in __globals:
        import logging
        logging.basicConfig(level=logging.INFO, format=logformat)

    if not isinstance(log, logging.Logger):
        log = logging.getLogger(log)

    import optparse
    optparser = optparse.OptionParser(
        usage="%prog [options] [input files]",
        version="%%prog %s" % version)

    optparser.add_option("-d", "--debug",
        action="store_true",
        help="log debug messages")

    optparser.add_option("-t", "--timer",
        action="store_true", default=False,
        help="log execution time")

    optparser.add_option("-T", "--test",
        action="store_true", default=False,
        help="run doctests instead of processing input")

    precompile_options = 'no partial full'.split()
    optparser.add_option("-c", "--precompile",
        action="store", choices=precompile_options + map(str, range(len(precompile_options))),
        help="precompile using psyco on python < 2.7 [0=no|1=partial|2=full]")

    optparser.add_option("-o", "--stdout",
        action="store_true", default=False,
        help="use (stdout|stderr) instead of {inputfilename}.(out|log)")

    optparser.add_option("-O", "--overwrite",
        action="store_true", default=False,
        help="overwrite existing {inputfilename}.out")

    optparser.set_defaults(precompile='partial')
    options, files = optparser.parse_args()
    try: options.precompile = int(options.precompile)
    except ValueError: options.precompile = precompile_options.index(options.precompile)

    # update global exported log proxy
    glog = __globals['log']
    [setattr(glog, m, getattr(log, m)) for m in dir(glog) if not m.startswith('__')]

    if options.debug:
        log.setLevel(logging.DEBUG)
        if options.stdout or not files:
            # much faster shortcut, when stderr is enough
            glog.debug=lambda message: sys.stderr.write('# DEBUG:  %s\n' % message)
        log.debug('options: %s' % ', '.join(['%s=%r' % (o, v) for o, v in options.__dict__.items()]))
        __globals.update(debug=log.debug)
    else:
        glog.debug = None

    if options.precompile and sys.version < '2.7':
        try:
            import psyco

            if options.precompile > 1:
                log.info('precompiling using psyco')
                psyco.full()
            else:
                if precompile is None:
                    precompile = []
                elif not isinstance(precompile, list):
                    precompile = list(precompile)
                precompile[0:0] = [solve, parse, format]
                precompile = [func for func in precompile if type(func)==type(main)]

                log.info('precompiling using psyco: %s' % ', '.join([f.__name__ for f in precompile]))
                [psyco.bind(f) for f in precompile]

        except ImportError, e:
            log.warning('psyco not imported: %s' % e)

    if options.timer:
        solve = timed(solve)

    __globals.update(solve=solve, parse=parse, format=format)

    if options.test:
        import doctest
        doctest.testmod()

    else:
        if files:
            import glob
            for mask in files:
                fins = glob.glob(mask)

                if not fins:
                    log.error("no files matching '%s' found" % mask)

                elif options.stdout:
                    for fin in fins:
                        try:
                            run(open(fin, 'rU'), sys.stdout)
                        except:
                            log.exception("file '%s':" % fin)

                else:
                    import os, os.path

                    # Log only errors to console. Detailed log will be in output.log.
                    if log.handlers:
                        log.handlers[0].level = logging.ERROR

                    for fin in fins:
                        fl = None
                        try:
                            fn = os.path.splitext(fin)[0]
                            fon = '%s.out' % fn
                            if not options.overwrite and os.path.exists(fon):
                                log.warning("skipped '%s': output file already exists" % fin)
                                continue
                            fl = logging.FileHandler('%s.log' % fn)
                            fl.setFormatter(logging.Formatter(logformat))
                            log.addHandler(fl)
                            log.info('FILE: %s' % fn)
                            fi = open(fin, 'rU')
                            fo = open(fon, 'w')
                            run(fi, fo)
                        except:
                            log.exception("file '%s':" % fin)
                            try:
                                fi.close()
                                fo.close()
                                os.remove(fon)
                            except:
                                c, e, t = sys.exc_info()
                                log.error("file '%s': unable to remove invalid output: %s: %s" % \
                                    (fin, getattr(c, '__name__', c), e))
                        finally:
                            if not fl is None:
                                try:
                                    log.removeHandler(fl)
                                except:
                                    log.exception("file '%s':" % fin)
        else:
            try:
                run(sys.stdin, sys.stdout)
            except:
                log.exception("file <stdin>:")
