import math


def read(f):
    return f(raw_input().strip())


def read_arr(f):
    return map(f, raw_input().strip().split(" "))

MAX = 100000.0


def f(T):
    B, N = read_arr(int)
    M = read_arr(float)
    if B == 1:
        print "Case %d: 1" % T
        return
    r = map(lambda x: MAX / x, M)
    tr = sum(r)
    t = (N-1)/tr
    cd = map(lambda x: int(x*t), r)
    time = min([M[i]*cd[i] for i in range(B)])
    cd = map(lambda x: time/x, M)
    alloted = sum([math.ceil(x) for x in cd])
    b = None
    while alloted < N:
        for i, m in enumerate(cd):
            if m == int(m):
                cd[i] += 10**-8
                alloted += 1
                if alloted == N:
                    b = i+1
                    print "Case #%d: %d" % (T, b)
                    return
        proceed_time = min([(math.ceil(cd[i]) - cd[i])*M[i] for i in range(B)])
        cd = [cd[i] + proceed_time/M[i] for i in xrange(B)]

if __name__ == "__main__":
    for T in xrange(input()):
        f(T+1)
