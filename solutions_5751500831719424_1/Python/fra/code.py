#!/usr/bin/python
# coding=utf8
import sys
from numpy import cross, dot, multiply, add, subtract
from numpy.linalg import norm
from itertools import permutations, combinations
import collections
import functools

hide_dots = len(sys.argv) > 1 and sys.argv[1] == "hide_dots"


def dbg(*args, **kwargs):
    first = True
    for i in args:
        if first:
            first = False
        else:
            sys.stderr.write(" ")
        sys.stderr.write(str(i))
    if 'no_line_jump' in kwargs and kwargs['no_line_jump']:
        pass
    else:
        sys.stderr.write("\n")


class memoized(object):
    '''Decorator. Caches a function's return value each time it is called.
    If called later with the same arguments, the cached value is returned
    (not reevaluated).
    '''
    def __init__(self, func):
        self.func = func
        self.cache = {}
    def __call__(self, *args):
        if not isinstance(args, collections.Hashable):
            return self.func(*args)
        if args in self.cache:
            return self.cache[args]
        else:
            value = self.func(*args)
            self.cache[args] = value
            return value
    def __repr__(self):
        '''Return the function's docstring.'''
        return self.func.__doc__
    def __get__(self, obj, objtype):
        '''Support instance methods.'''
        return functools.partial(self.__call__, obj)


def main():
    data = sys.stdin
    nb = int(data.readline())
    for icase in xrange(nb):
        if not hide_dots:
            dbg(".", no_line_jump=True)

        nb_strings = int(data.readline())
        strings = []
        for istring in xrange(nb_strings):
            strings.append(data.readline().strip())

        # for each unique char, get max char et essayer tous les chars
        chars = []
        prev_c = '0'
        for c in strings[0]:
            if c != prev_c:
                chars.append(c)
                prev_c = c

        # pour chaque char, cherche le moins de modif pour que tout le monde
        # ait pareil
        possible = True
        cur_idx = [0] * nb_strings
        total_changes = 0
        for c in chars:
            #print c, cur_idx
            count_char = []
            for idx, s in enumerate(strings):
                nb_c = 0
                while True:
                    if cur_idx[idx] >= len(s):
                        break
                    if s[cur_idx[idx]] == c:
                        nb_c += 1
                        cur_idx[idx] += 1
                    else:
                        break
                if nb_c == 0:
                    possible = False
                else:
                    count_char.append(nb_c)
            # we have all the counts, take the sum and move to the nearest
            #print c, count_char
            # try all values from min to max
            best_val = -1
            min_c = min(count_char)
            max_c = max(count_char)
            #print min_c, max_c
            for itry in range(min_c, max_c + 1):
                changes = sum([abs(a-itry) for a in count_char])
                if changes < best_val or best_val == -1:
                    best_val = changes
            #print best_val
            total_changes += best_val
            #print "sum:", total_changes

            if not possible:
                break

        # check if all indices are at the end
        all_at_end = all([cur_idx[i] == len(strings[i]) for i in xrange(nb_strings)])

        if not possible or not all_at_end:
            res = "Fegla Won"
        else:
            res = str(total_changes)




        #lint = map(int, data.readline().split())
        #lfloat = map(float, data.readline().split())
        #lstring = data.readline().split()
        #string = data.readline().strip()
        print "Case #%d: %s" % (icase + 1, res)


if __name__ == "__main__":
    main()
