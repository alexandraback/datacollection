from heapq import heappush, heappop

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def lcm(a, b):
    return a * b / gcd(a, b)

def mlcm(l):
    return reduce(lcm, l)

T = int(raw_input())
for t in range(T):
    B, N = map(int, raw_input().split())
    M = map(int, raw_input().split())
    h = []
    for i in range(B):
        heappush(h, (0, i))
    max_time = mlcm(M)
    barbers = []
    time, b_id = 0, 0
    while True:
        time, b_id = heappop(h)
        if (time, b_id) == (max_time, 0):
            break
        barbers.append(b_id)
        heappush(h, (time + M[b_id], b_id))
    # print(barbers)
    print 'Case #%d: %s' % (t + 1, barbers[(N - 1) % len(barbers)] + 1)
