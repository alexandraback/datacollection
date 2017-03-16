def gcd(a, b):
    while b:      
        a, b = b, a%b
    return a

def lcm(a, b):
    return a*b/gcd(a, b)

for tc in range(1, int(raw_input())+1):
    b, n = map(int, raw_input().split())
    m = map(int, raw_input().split())
    
    period = reduce(lcm, m)
    n = (n-1) % sum(period/i for i in m)

    step = reduce(gcd, m)
    time = 0
    done = False
    while not done:
        for i, mi in enumerate(m):
            if time % mi == 0:
                if n == 0:
                    print 'Case #%d: %d' % (tc, i+1)
                    done = True
                    break
                else:
                    n -= 1
        time += step
    
    
    
