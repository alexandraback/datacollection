__author__ = 'bszikszai'


def getMost(n, t):
    mc = 0
    mci = None
    for (nm, c) in n.iteritems():
        rt = c / float(t)
        if (rt > mc):
            mc = rt
            mci = (nm, c, rt)
    return mci

def simulate(n, t):
    res = ""
    while True:
        if t == 0:
            return res
        (nm, ctr, rt) = getMost(n, t)
        t-=1
        n[nm] -= 1
        res = res + nm
        if t == 0:
            return res
        (nm, ctr, rt) = getMost(n, t)
        if rt > 0.5:
            n[nm] -= 1
            t -= 1
            res = res + nm
        res = res + " "

def solve(f):
    foo = f.readline()
    inp = [int(x) for x in f.readline().rstrip('\n\r ').split(' ')]
    res = {}
    total = 0
    for i in range(0, len(inp)):
        res[str(unichr(65+i))] = inp[i]
        total += inp[i]
    return simulate(res, total)

with open('input.txt', 'r') as f:
    with open('output.txt', 'wb') as g:
        cases = int(f.readline())
        for i in range(0, cases):
            solution = solve(f)
            print "Case #%s: %s" % (i+1, solution)
            g.write("Case #%s: %s\n" % (i+1, solution))