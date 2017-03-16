def read_list_int():
    return [int(x) for x in input().split(' ')]

def ceil(a, b):
    return (a + b - 1) / b

def solve():
    b, n = read_list_int()
    barb_times = read_list_int()

    def finished_or_seating(t):
        finished = 0
        for barb_time in barb_times:
            finished += t // barb_time
        return finished + b

    l, r, sr, res = 0, 10**16, -1, -1
    while l<=r:
        sr = (l+r)//2
        if finished_or_seating(sr) >= n:
            res = sr
            r = sr - 1
        else:
            l = sr + 1

    starting_at_res = [ i for i in range(b) if res % barb_times[i] == 0]

    finished_at_res = finished_or_seating(res) - len(starting_at_res)

    n -= finished_at_res
    my_idx = starting_at_res[n-1] + 1
    return my_idx


if __name__ == '__main__':
    cases = int(input())
    for case in range(1, cases+1):
        print('Case #%d: %s' % (case, str(solve())))
