__author__ = 'ar'

def _solve():
    pass

def _input():
    pass

# rate1 ->
# rate2 -> x y
# rate is always >= y - x

if __name__ == "__main__":
    t = int(input())
    for idx in range(0, t):
        N = int(input())

        wts = [int(i) for i in raw_input().split(' ')]

        res1 = 0
        res2 = 0
        prev = 0

        min_rate = 0
        for w in wts:
            if w < prev:
                res1 += prev - w
                min_rate = max(min_rate, prev - w)

            prev = w

        prev = wts[0]
        for i in range(1, len(wts)):
            res2 += min(min_rate, prev)
            prev = wts[i]

        print "Case #%d: %d %d" % (idx + 1, res1, res2)

