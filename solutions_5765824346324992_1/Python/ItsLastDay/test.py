def f(m, t):
    cur = 0
    for x in m:
        cur += t // x
    return cur

def solve():
    n, place = map(int, input().split())
    m = list(map(int, input().split()))

    left = 0
    right = 10 ** 100
    while right - left > 1: 
        mid = (left + right) // 2
        if f(m, mid) >= place - 1:
            right = mid
        else:
            left = mid

    prev = f(m, right - 1)
    over = f(m, right) - max(prev, place)
    t = sorted([(m[i], i + 1) for i in range(len(m)) if right % m[i] == 0])
    for i in range(len(t)):
        if prev + i + 1 == place:
            return t[i][1]
    return t[over][1]

for test in range(1, int(input()) + 1):
    print('Case #%d: %d' % (test, solve()))
