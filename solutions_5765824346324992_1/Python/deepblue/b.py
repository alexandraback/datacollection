__author__ = 'ar'

def done_or_in_flight(wts, cur_time):
    res = 0
    for w in wts:
        if cur_time % w == 0:
            res += cur_time / w
        else:
            res += int(cur_time / w) + 1
    return res


def search(wts, N):
    mn = 0
    mx = 100000 * 1000000000 + 1

    while mn < mx:
        mid = int((mx + mn) / 2)
        if done_or_in_flight(wts, mid) >= N:
            mx = mid
        else:
            mn = mid + 1

    return mn

if __name__ == "__main__":
    t = int(input())
    for idx in range(0, t):
        parts = raw_input().split(' ')
        B, N = int(parts[0]), int(parts[1])
        times = [int(i) for i in raw_input().split(' ')]
        served_at = search(times, N) - 1
        # There could be multiple people
        num_done = done_or_in_flight(times, served_at)
        candidates = [(i, w) for i, w in enumerate(times) if served_at % w == 0]
        res = candidates[N - num_done - 1][0]
        print "Case #%d: %d" % (idx + 1, res + 1)


