from sys import stdin

T = int(stdin.readline())

for _ in range(T):
    stdin.readline()
    m = map(int, stdin.readline().split())

    ans1 = 0
    for i in range(len(m)-1):
        ans1 += max(0, m[i] - m[i+1])

    rate = 0
    for i in range(len(m)-1):
        rate = max(rate, m[i] - m[i+1])

    ans2 = 0
    for i in range(len(m)-1):
        ans2 += min(rate, m[i])

    print "Case #{}: {} {}".format(_+1, ans1, ans2)
