# Qualification Round 2014
# Problem A. Magic Trick
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

def solve(r1,arr1,r2,arr2):
    pos1 = set(arr1[r1-1])
    pos2 = set(arr2[r2-1])
    sol = pos1 & pos2
    if len(sol)==0:
        return "Volunteer cheated!"
    if len(sol)>1:
        return "Bad magician!"
    return sol.pop()
    
def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        r1 = int(raw_input())
        arr1 = [map(int, raw_input().split(' ')) for line in xrange(4)]
        r2 = int(raw_input())
        arr2 = [map(int, raw_input().split(' ')) for line in xrange(4)]
        print 'Case #%d: %s' % (tc, solve(r1,arr1,r2,arr2))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""3
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 5 4
3 11 6 15
9 10 7 12
13 14 8 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.ERROR)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
