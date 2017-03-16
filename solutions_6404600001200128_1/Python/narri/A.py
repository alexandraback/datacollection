import sys

def _cc():
    for line in sys.stdin:
        for x in line.strip().split():
            yield x

_cin = _cc()
cin = _cin.next

def solve_1(data):
    out = 0
    for i in xrange(len(data)-1):
        if data[i+1] < data[i]:
            out += data[i] - data[i+1]
    return out

def solve_2(data):
    out = 1e99
    for rate in xrange(0, 10001):
        s = 0
        curr = data[0]
        for t in data[1:]:
            z = min(curr, rate)
            s += z
            curr -= z
            if curr > t:
                break
            curr = t
        else:
            out = min(out, s)
    return out

T = int(cin())
for cn in xrange(1,T+1):
    N = int(cin())
    data = list(int(cin()) for t in xrange(N))
    print "Case #%d: %d %d" % (cn, solve_1(data), solve_2(data))
