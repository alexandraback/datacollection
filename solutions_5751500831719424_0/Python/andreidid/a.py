import sys

def debug(msg):
    print >> sys.stderr, msg
from collections import Counter

def solve(f, t):
    n = int(f.readline())
    a = []
    for i in xrange(n):
        a.append(f.readline().strip())
    s = []
    first = a[0]
    for i in xrange(1, len(first)):
        if first[i] != first[i-1]:
            s.append(first[i-1])
    s.append(first[-1])
    s = ''.join(s)
    count = [ [0] * len(s) for _ in xrange(n)]
    for i in xrange(n):
        count[i][0] = 1
        pos = 0
        for j in xrange(1, len(a[i])):
            if s[pos] != a[i][j-1]:
                return 'Fegla Won'
            if a[i][j] == a[i][j-1]:
                count[i][pos] += 1
            else:
                pos += 1
                if pos >= len(s):
                    return 'Fegla Won'
                #print i, pos, len(s)
                count[i][pos] = 1
        if pos != len(s) - 1 or s[pos] != a[i][-1]:
            return 'Fegla Won'
    ret = 0
   # print a
   # print count
    for j in xrange(len(s)):
        c = Counter()
        v = []
        for i in xrange(n):
            v.append(count[i][j])

        v = sorted(v)
    #    print v
        mid = v[len(v)/2]
        u = 0
        for i in xrange(len(v)):
            u += abs(v[i] - mid)
        ret += u
    return ret

if __name__=='__main__':
    f = sys.stdin
    T = int(f.readline())
    for t in xrange(T):
        ret = solve(f, t)
        print 'Case #%s: %s' % (t+1, ret)
