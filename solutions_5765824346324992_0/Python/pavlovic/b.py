import sys

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

t = int(sys.stdin.readline().strip())

for i in range(t):
    b, n = sys.stdin.readline().strip().split()
    b = int(b)
    n = int(n)
    m = sys.stdin.readline().strip().split()
    for j in range(b):
        m[j] = int(m[j])

    l = lcmm(*m)
    p = 0
    for j in range(b):
        p += l / m[j]

    n = (n - 1) % p + 1

    t = [0] * b
    q = 0
    for j in range(n):
        q = 0
        for k in range(1, b):
            if t[k] < t[q]:
                q = k

        t[q] += m[q]

    print "Case #%d: %d" % (i + 1, q + 1)
