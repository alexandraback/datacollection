m = 0
ans = 10000
left = 10000
stats = []
row = 0

def update():
    global ans
    now = 0
    for i in xrange(m):
        if stats[i]:
            if i >= row:
                now += stats[i - row]
            if i % row:
                now += stats[i - 1]
    if now < ans:
        ans = now

def rec(x):
    global left
    if x == m:
        update()
    else:
        if left:
            stats[x] = 1
            left -= 1
            rec(x + 1)
            left += 1
        if left < m - x:
            stats[x] = 0
            rec(x + 1)

def solve(R, C, N):
    global m
    global left
    global stats
    global ans
    global row
    row = R
    ans = 10000
    left = N
    m = R * C
    stats = [0] * m
    rec(0)
    return ans


def main():
    T = input()
    for i in xrange(1, T + 1):
        line = raw_input()
        R, C, N = map(int, line.strip().split())
        print 'Case #{0}: {1}'.format(i, solve(R, C, N))

if __name__ == '__main__':
    main()
