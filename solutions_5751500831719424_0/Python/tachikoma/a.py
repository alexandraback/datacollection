import sys
#from collections import defaultdict

def words(astr):
    if len(astr) == 0:
        return []
    w = []
    x0, c = astr[0], 1
    for x in astr[1:]:
        if x != x0:
            w.append((x0, c))
            x0, c = x, 0
        c += 1
    w.append((x0, c))
    return w

def min_middle(counts):
    counts.sort()
    x_min = float('inf')
    for n in range(counts[0], counts[-1]+1):
        x = 0
        for c in counts:
            x += abs(n - c)
        if x_min > x:
            x_min = x
    return x_min

def solve(words):
    w0 = words.pop()
    x = 0
    while w0:
        c0 = w0.pop()
        counts = [c0[1]]
        for w in words:
            if len(w) == 0 or w[-1][0] != c0[0]:
                return "Fegla Won"
            counts.append(w.pop()[1])
        x += min_middle(counts)
    for w in words:
        if w:
            return "Fegla Won"
    return x


f = open(sys.argv[1])
T = int(f.readline())
for t in xrange(1,T+1):
    n = int(f.readline().strip())
    w = []
    for i in range(n):
        w.append(words(f.readline().strip()))

    print "Case #{0}: {1}".format(t, solve(w))
