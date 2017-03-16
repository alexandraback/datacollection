import math


def parse(s):
    r = []
    p = None
    for c in s:
        if p != c:
            r.append([c, 1])
        else:
            r[-1][1] += 1
        p = c
    return r


def solve(A):
    n = len(A)
    A.sort()
    S = sum(A)
    l = 0
    #print A
    res = S
    for i, a in enumerate(A):
        l += A[i-1] if i > 0 else 0
        r = S - a - l
        # print l, a, r, "=>", a * i - l, r - a * (n - i - 1), a * i - l + r - a * (n - i - 1)
        res = min(res, a * i - l + r - a * (n - i - 1))
    # print A, res
    return res


def CASE(IN):
    def rstr():
        return IN.readline().strip()

    def rint():
        return int(rstr())

    def rints():
        return map(int, rstr().split())
    N = rint()
    sig = None
    a = []
    for i in xrange(N):
        s = rstr()
        r = parse(s)
        t = ''.join(x for x, _ in r)
        if sig is None:
            sig = t
            for c, v in r:
                a.append([v])
            continue
        elif sig != t:
            return "Fegla Won"
        for j, t in enumerate(r):
            a[j].append(t[1])
    return sum(map(solve, a))


def RUN(IN, OUT):
    t = int(IN.readline().strip())
    for i in xrange(1, t + 1):
        OUT.write("Case #%i: %s\n" % (i, CASE(IN)))

if __name__ == "__main__":
    import sys
    RUN(sys.stdin, sys.stdout)
