# Round 1B 2014
# Problem A. The Repeater
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

def reduce_string(s):
    res = [s[0]]
    for c in s[1:]:
        if res[-1]!=c:
            res.append(c)
    return "".join(res)

def string_lens(strings,red):
    res = [[0 for n in xrange(len(strings))] for c in red]
    for i1,s in enumerate(strings):
        ls = len(s)
        counts=[]
        i=0
        count=0
        for i2,c in enumerate(red):
            while i<ls and s[i]==c:
                count+=1
                i+=1
            res[i2][i1] = count
            count=0
        # res.append(counts)
    return res

def repeater1(lens):
    minops = 1000000
    for n in xrange(min(lens),max(lens)+1):
        ops = sum(abs(n-l) for l in lens)
        if ops<minops:
            minops=ops
    return minops

def solve(n,strings):
    reds = map(reduce_string,strings)
#    print reds
    if len(set(reds))>1:
        return "Fegla Won"
    red = reds[0]
#    print red
    llens = string_lens(strings,red)
#    print llens
#    print map(repeater1,llens)
    return str(sum(map(repeater1,llens)))

def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        n = int(raw_input())
        strings = [raw_input() for i in xrange(n)]
        print 'Case #%d: %s' % (tc, solve(n,strings))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""5
2
mmaw
maw
2
gcj
cj
3
aaabbb
ab
aabb
2
abc
abc
3
aabc
abbc
abcc
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.ERROR)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
