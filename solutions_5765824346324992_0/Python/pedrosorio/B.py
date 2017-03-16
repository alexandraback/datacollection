import heapq

T = int(raw_input())

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return abs(a * b) / gcd(a,b)

def solve(m, n):
    min_time = reduce(lambda x,y: x*y, m)
    heap = [(0, i) for i in xrange(len(m))]
    c = 1
    period = []
    while c < n:
        t, barber = heapq.heappop(heap)
        if t <= min_time:
            period.append(barber)
        else:
            break
        heapq.heappush(heap, (t+m[barber], barber))
        c += 1
    if c == n:
        return heapq.heappop(heap)[1] + 1
    else:
        return period[(n-1)%len(period)] + 1

for case in xrange(1,T+1):
    B, N = map(int,raw_input().split())
    m = map(int,raw_input().split())
    x = solve(m, N)
    print "Case #{}: {}".format(case, x)
