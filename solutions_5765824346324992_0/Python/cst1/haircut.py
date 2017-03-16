import sys


class Haircut:

    def get_cycle(self, m, cycle_len):
        available = range(len(m))
        cutting = []
        cycle = []
        for _ in range(cycle_len):
            if len(available) == 0:
                m_barber = max(cutting, key=lambda v: (-v[1], -v[0]))
                cutting.remove(m_barber)
                t = m_barber[1]
                cutting = map(lambda v: (v[0], v[1] - t), cutting)
                available.append(m_barber[0])

            barber = min(available)
            cycle.append(barber)
            available.remove(barber)
            cutting.append((barber, m[barber]))
        return cycle

    def get_cycle_len(self, m):
        cycle_len = 1
        max_m = max(m)
        while sum(map(lambda v: (max_m * cycle_len) % v == 0, m)) != len(m):
            cycle_len += 1
        return reduce(lambda s, v: s + (cycle_len * max_m) / v, m, 0)

    def solve_case(self, f):
        b, n = map(int, f.readline().split())
        m = map(int, f.readline().split())
        cycle_len = self.get_cycle_len(m)
        cycle = self.get_cycle(m, cycle_len)
        return cycle[(n-1) % cycle_len] + 1

    def create_report(self, ci, r):
        r = ", ".join(map(str, r)) if not isinstance(r, str) and isinstance(r, (list, tuple)) else str(r)
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
    h = Haircut()

    if len(sys.argv) < 2:
        h.solve_and_save(sys.stdout, sys.stdin)
    else:
        f = open("./in/" + sys.argv[1] + ".in", 'r')
        o = open("./out/" + sys.argv[1] + ".out", 'w')
        h.solve_and_save(o, f)
        f.close()
        o.close()
