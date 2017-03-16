data_in = open("B-small-attempt3.in", "r")
data_out = open("Haircut.out", "w")

T = int(data_in.readline())

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

for t in xrange(T):
    args = data_in.readline().split()
    B = int(args[0])
    N = int(args[1])
    M = [int(x) for x in data_in.readline().split()]
    m = [0]
    test = True
    for i in xrange(1, B):
        if M[i] != M[i-1]:
            test = False
        m.append(0)
    if test:
        free = N%B
        if free == 0:
            free = B
        data_out.write("Case #%d: %d\n"%(t+1, free))
        continue

    m_lcm = lcmm(*M)
    n = 0
    for i in xrange(B):
        n += m_lcm/M[i]
    if N > n:
        p = N/n
        N = N-p*n
        if N == 0:
            N = n

    n = 0
    while True:
        while 0 in m:
            n += 1
            free = m.index(0)
            if n == N:
                data_out.write("Case #%d: %d\n"%(t+1, free+1))
                break
            m[free] = M[free]

        if n == N:
            break
        minute = min(m)
        for i in xrange(B):
            m[i] -= minute


data_in.close()
data_out.close()
