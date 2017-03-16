import sys


class MushroomMonster:

    def first_method(self, counts):
        res = 0
        for c1, c2 in zip(counts, counts[1:]):
            if c1 > c2:
                res += c1 - c2
        return res

    def second_method(self, counts):
        m = 0
        for c1, c2 in zip(counts, counts[1:]):
            if c1 > c2:
                m = max(m, c1 - c2)
        tot = 0
        for c in counts[:-1]:
            tot += min(c, m)
        return tot

    def solve_case(self, f):
        f.readline()
        counts = map(int, f.readline().split())
        return self.first_method(counts), self.second_method(counts)

    def create_report(self, ci, r):
        r = " ".join(map(str, r)) if not isinstance(r, str) and isinstance(r, (list, tuple)) else str(r)
        return "Case #" + str(ci) + ": " + r

    def solve(self, f):
        t = int(f.readline())
        results = []
        for c in range(t):
            results.append(self.solve_case(f))
        return "\n".join(map(lambda c: self.create_report(c[0] + 1, c[1]), enumerate(results)))

    def solve_and_save(self, out, f):
        out.write(self.solve(f))

if __name__ == "__main__":
    mm = MushroomMonster()

    if len(sys.argv) < 2:
        mm.solve_and_save(sys.stdout, sys.stdin)
    else:
        f = open("./in/" + sys.argv[1] + ".in", 'r')
        o = open("./out/" + sys.argv[1] + ".out", 'w')
        mm.solve_and_save(o, f)
        f.close()
        o.close()
