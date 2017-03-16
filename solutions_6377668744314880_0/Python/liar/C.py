def solve(ps):
    assert(len(set(ps)) == len(ps))

    from math import atan2

    def gcd(a, b):
        while b != 0:
            a, b = b, a % b
        return a

    def compute_angle(v):
        x, y = v
        d = gcd(x, y)
        return atan2(y // d, x // d)

    def depth(p, ps):
        x0, y0 = p
        ps = [(x - x0, y - y0) for (x, y) in ps if (x, y) != (x0, y0)]
        ps_hi = [(+x, +y) for (x, y) in ps if y > 0 or y == 0 and x > 0]
        ps_lo = [(-x, -y) for (x, y) in ps if y < 0 or y == 0 and x < 0]
        as_hi = sorted((compute_angle(p) for p in ps_hi), reverse=True)
        as_lo = sorted((compute_angle(p) for p in ps_lo), reverse=True)
        cnt_hi, b_hi = len(as_hi), 0
        cnt_lo, b_lo = len(as_lo), 0
        ans = min(cnt_hi, cnt_lo)
        while as_hi or as_lo:
            cnt_hi, cnt_lo = cnt_hi + b_lo, cnt_lo + b_hi
            ans = min([ans, cnt_hi, cnt_lo])
            
            a_hi_min, a_lo_min = float("inf"), float("inf")
            if as_hi: a_hi_min = as_hi[-1]
            if as_lo: a_lo_min = as_lo[-1]
            a = min(a_hi_min, a_lo_min)
            b_hi = 0
            while as_hi and as_hi[-1] == a:
                as_hi.pop()
                b_hi += 1
            b_lo = 0
            while as_lo and as_lo[-1] == a:
                as_lo.pop()
                b_lo += 1

            cnt_hi, cnt_lo = cnt_hi - b_hi, cnt_lo - b_lo
            ans = min([ans, cnt_hi, cnt_lo])
        return ans

    return "\n".join(str(depth(p, ps)) for p in ps)

def parse_problems():
    import fileinput
    fin = fileinput.input()

    T = int(next(fin))
    for _ in range(T):
        N = int(next(fin))
        ps = []
        for i in range(N):
            p = list(map(int, next(fin).split()))
            assert(len(p) == 2)
            x, y = p
            ps.append((x, y))
        yield ps

def main():
    for i, p in enumerate(parse_problems()):
        ans = solve(p)
        print("Case #{}:\n{}".format(i + 1, ans))

if __name__ == '__main__':
    main()