
if __name__ == "__main__":
    T = int(raw_input())
    for test in xrange(T):
        N = int(raw_input())
        amount = [int(i) for i in raw_input().split(" ")]
        co_1, co_2 = 0, 0
        for idx, ele in enumerate(amount):
            if idx > 0:
                if amount[idx] < amount[idx-1]:
                    co_1 += amount[idx-1] - amount[idx]
        max_diff = 0
        for idx, ele in enumerate(amount):
            if idx > 0:
                if amount[idx] < amount[idx-1]:
                    max_diff = max(max_diff, amount[idx-1] - amount[idx])
        for idx, ele in enumerate(amount):
            if idx < len(amount) - 1:
                if amount[idx] <= max_diff:
                    co_2 += amount[idx]
                else:
                    co_2 += max_diff
                # amount[idx+1] +=
        print "Case #%d: %d %d" % (test + 1, co_1, co_2)