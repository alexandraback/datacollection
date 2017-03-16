import sys


class NoisyNeighbors:
    def unhappiness(self, occupied, x, y):
        return sum([
            occupied[y + dy][x + dx]
            for dy in range(-1, 2)
            for dx in range(-1, 2)
            if 0 <= y + dy < len(occupied)
            if 0 <= x + dx < len(occupied[y])
            if abs(dx) + abs(dy) == 1
        ])

    def list_unhappiness(self, r, c, occupied_l):
        occupied = [[False] * c for _ in range(r)]
        for x, y in occupied_l:
            occupied[y][x] = True
        tot = 0
        for x, y in occupied_l:
            tot += self.unhappiness(occupied, x, y)
        return tot / 2

    def solve_case_rec(self, r, c, n, x=0, y=0, occupied=None):
        if occupied is None:
            occupied = []

        if n < 0:
            return sys.maxint

        if y == r:
            if n == 0:
                return self.list_unhappiness(r, c, occupied)
            return sys.maxint

        ny = y + (x + 1)/c
        nx = (x + 1) % c

        return min(
            self.solve_case_rec(r, c, n - 1, nx, ny, occupied + [(x, y)]),
            self.solve_case_rec(r, c, n, nx, ny, occupied))

    def solve_case(self, f):
        r, c, n = map(int, f.readline().split())
        return self.solve_case_rec(r, c, n)

    def create_report(self, ci, r):
        r = ", ".join(map(str, r)) if not isinstance(r, str) and isinstance(r, (list, tuple)) else str(r)
        return "Case #" + str(ci) + ": " + r

    def solve(self, f):
        t = int(f.readline())
        results = []
        for c in range(t):
            print c
            results.append(self.solve_case(f))
        return "\n".join(map(lambda c: self.create_report(c[0] + 1, c[1]), enumerate(results)))

    def solve_and_save(self, out, f):
        out.write(self.solve(f))

if __name__ == "__main__":
    nn = NoisyNeighbors()

    if len(sys.argv) < 2:
        nn.solve_and_save(sys.stdout, sys.stdin)
    else:
        f = open("./in/" + sys.argv[1] + ".in", 'r')
        o = open("./out/" + sys.argv[1] + ".out", 'w')
        nn.solve_and_save(o, f)
        f.close()
        o.close()
