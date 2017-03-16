T = int(raw_input())


# IN TIME PANIC I TOOK THIS FROM SO!!!!
# http://stackoverflow.com/questions/147515/least-common-multiple-for-3-or-more-numbers
def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""   
    return reduce(lcm, args)

for t in xrange(1, T+1):
    B, N = [int(x) for x in raw_input().split()]
    M = [int(m) for m in raw_input().split()]
    LCM = lcmm(*M)
    ORDER = []
    for b in xrange(B):
        for x in xrange(0, LCM, M[b]):
            ORDER.append((x, b))
    ORDER.sort()
    barber = ORDER[(N - 1) % len(ORDER)][1] + 1

    print 'Case #{}: {}'.format(t, barber)
    
