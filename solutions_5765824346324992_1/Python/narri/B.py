import sys

def _cc():
    for line in sys.stdin:
        for x in line.strip().split():
            yield x

_cin = _cc()
cin = _cin.next

def num_cuts(barbers, mytime):
    return sum(mytime//b for b in barbers) + len(barbers)

def solve(barbers, placement):
    low = 0
    high = 1024
    while num_cuts(barbers, high) < placement:
        high *= 2
    mid = None
    while high - low > 10:
        mid = low + ((high-low)//2)
        if num_cuts(barbers, mid) < placement:
            low = mid + 1
        else:
            high = mid
    while num_cuts(barbers, low) < placement:
        low += 1
    counter = placement - (num_cuts(barbers, low-1) if low > 0 else 0)
    #now low represents the wait time
    for i, b in enumerate(barbers):
        if low % b == 0:
            counter -= 1
            if counter == 0:
                break
    return i+1

T = int(cin())
for cn in xrange(1,T+1):
    N, P = int(cin()), int(cin())
    data = list(int(cin()) for t in xrange(N))
    print "Case #%d: %d" % (cn, solve(data, P))
