import bisect


def calc(time, array):
    if time < 0:
        return 0
    ret = len(array)
    for a in array:
        ret += time / a
    return ret

def just(time, array):
    ret = []
    for i, a in enumerate(array):
        if time % a == 0:
            ret.append(i + 1)
    return ret

if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(1, T + 1):
        B, N = map(int, raw_input().split())
        M = map(int, raw_input().split())
        pre = 10 ** 15 + 10
        post = -1
        while pre - post > 1:
            cur = (pre + post) / 2
            tmp = calc(cur, M)
            if tmp >= N:
                pre = cur
            elif tmp < N:
                post = cur
        rest = N - calc(post, M)
        print "Case #%d: %d" % (t, just(pre, M)[rest - 1])