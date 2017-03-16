from fractions import gcd


def lcm(a, b):
    return a * b / gcd(a, b)

if __name__ == "__main__":
    T = int(raw_input())
    for test in xrange(T):
        n_barbers, position = [int(i) for i in raw_input().split(" ")]
        times = [int(i) for i in raw_input().split(" ")]
        total_lcm = 1
        for idx, time in enumerate(times):
            total_lcm = lcm(total_lcm, time)
        time_mark = {}
        cycle_size = 0
        for idx, time in enumerate(times):
            mul = total_lcm / time
            for m in range(mul):
                val = m * time
                if val not in time_mark:
                    time_mark[val] = []
                time_mark[val].append(idx + 1)
            cycle_size += mul
        position %= cycle_size
        result = None
        total_list = []
        for key in sorted(time_mark.keys()):
            lst = time_mark[key]
            lst.sort()
            total_list.extend(lst)
            # lst = time_mark[key]
            # if position > len(lst):
            #     position -= len(lst)
            # else:
            #     lst.sort()
            #     result = lst[position-1]
            #     break
        result = total_list[position-1]
        print "Case #%d:" % (test + 1), result