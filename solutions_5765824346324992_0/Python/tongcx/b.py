from sys import stdin

def go():
    l = 0
    r = 10**14 + 1

    while l <= r:
        t = (l + r) / 2
        finished = 0
        ongoing = 0
        now = 0

        for m in M:
            finished += t / m
            if t % m == 0:
                now += 1
            else:
                ongoing += 1

        # print t, finished, ongoing, now

        if finished + ongoing >= N:
            r = t - 1
        elif finished + ongoing + now < N:
            l = t + 1
        else:
            return [i for i, m in enumerate(M) if t % m == 0][N - finished - ongoing - 1]

T = int(stdin.readline())

for _ in range(T):
    B, N = map(int, stdin.readline().split())
    M = map(int, stdin.readline().split())

    print "Case #{}: {}".format(_+1, go()+1)
