def solve(problem):
    N, ms = problem

    def number_of_served_customers(t):
        return sum(t // m + 1 for m in ms)

    def bisect(func, x, lo, hi):
        while lo < hi:
            mid = (lo + hi) // 2
            if func(mid) < x:
                lo = mid+1
            else:
                hi = mid
        return lo

    lo, hi = 0, min(ms) * N
    t = bisect(number_of_served_customers, N, lo, hi)
    n = number_of_served_customers(t - 1)
    assert(n < N)
    for i, m in enumerate(ms):
        if t % m:
            continue
        n += 1
        if n == N:
            return i + 1
    assert(False)

def parse_problems():
    import fileinput
    fin = fileinput.input()

    T = int(next(fin))
    for _ in range(T):
        B, N = list(map(int, next(fin).split()))
        ms = list(map(int, next(fin).split()))
        assert(len(ms) == B)
        assert(N >= 1)
        yield N, ms

def main():
    for i, p in enumerate(parse_problems()):
        ans = solve(p)
        print("Case #{}: {}".format(i + 1, ans))

if __name__ == '__main__':
    main()