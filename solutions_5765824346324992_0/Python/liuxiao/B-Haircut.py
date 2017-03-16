import heapq

def input_line():
    return map(int, raw_input().split())

def gcd(a, b):
    if b > a:
        a, b = b, a
    while b:
        a, b = b, a % b
    return a

def reset_num(mb):
    lcm = mb[0]
    for num in mb[1:]:
        lcm = lcm * num / gcd(lcm, num)
    count = 0
    for num in mb:
        count += lcm / num
    return count

def solve(mb, n):
    h = []
    for i in range(len(mb)):
        heapq.heappush(h, (0, i))
    for i in range(n):
        time, index = heapq.heappop(h)
        heapq.heappush(h, (time + mb[i % len(mb)], index))
    return index

T = input()
for t in range(T):
    b, n = input_line()
    mb = map(int, raw_input().split())[:b]
    reset = reset_num(mb)
    n %= reset
    if n < 1:
        n = reset
    index = solve(mb, n)
    print "Case #%d: %d" % (t + 1, index + 1)
