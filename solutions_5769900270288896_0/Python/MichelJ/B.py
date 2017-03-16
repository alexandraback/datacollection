# Round 1B 2015
# Problem B. Noisy Neighbors
# MichelJ

import sys
import logging
import StringIO
from itertools import chain

def echo(fn):
    def wrapped(*v, **k):
        name = fn.__name__
        logging.info( "Called %s(%s)" % (name, ", ".join(map(repr, chain(v, k.values())))) )
        res = fn(*v, **k)
        logging.info( "       %s(%s) returned %s" % (name, ", ".join(map(repr, chain(v, k.values()))),res) )
        return res
    return wrapped

class memoized(object):
   """Decorator that caches a function's return value each time it is called.
   If called later with the same arguments, the cached value is returned, and
   not re-evaluated.
   """
   def __init__(self, func):
      self.func = func
      self.cache = {}
   def __call__(self, *args):
      try:
         return self.cache[args]
      except KeyError:
         value = self.func(*args)
         self.cache[args] = value
         return value
      except TypeError:
         # uncachable -- for instance, passing a list as an argument.
         # Better to not cache than to blow up entirely.
         return self.func(*args)
   def __repr__(self):
      """Return the function's docstring."""
      return self.func.__doc__
   def __get__(self, obj, objtype):
      """Support instance methods."""
      return functools.partial(self.__call__, obj)


def unhap(R, C, svec):
    res = 0
    for r in xrange(R):
        for c in xrange(C-1):
            if svec[r*C + c] == "1" and svec[r*C + c + 1] == "1":
                res += 1
    for r in xrange(R-1):
        for c in xrange(C):
            if svec[r*C + c] == "1" and svec[(r+1)*C + c] == "1":
                res += 1
    return res    

def solve(R,C,N):
    minuh = (R+1)*(C+1)
    for vec in xrange(1<<(R*C)):
        svec = bin(vec)[2:]
        svec = (R*C - len(svec))*'0' + svec
        if svec.count('1') == N:
            uh = unhap(R, C, svec)
            if uh < minuh:
                minuh = uh
    return str(minuh)
    
def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        R,C,N = map(int, raw_input().split(' '))
        print 'Case #%d: %s' % (tc, solve(R,C,N))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""4
2 3 6
4 1 2
3 3 8
5 2 0
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.INFO)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
