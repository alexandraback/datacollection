def solve(problem):
    ms = problem
    ds = [ms[i] - ms[i + 1] for i in range(0, len(ms) - 1)]
    t1 = sum(d for d in ds if d > 0)
    v = max(ds)
    if v > 0:
        t2 = sum(min(v, m) for m in ms[:-1])
    else:
        t2 = 0

    return "{} {}".format(t1, t2)

def parse_problems():
    import fileinput
    fin = fileinput.input()

    T = int(next(fin))
    for _ in range(T):
        N = int(next(fin))
        ms = list(map(int, next(fin).split()))
        assert(len(ms) == N)
        assert(N > 1)
        yield ms

def main():
    for i, p in enumerate(parse_problems()):
        ans = solve(p)
        print("Case #{}: {}".format(i + 1, ans))

if __name__ == '__main__':
    main()