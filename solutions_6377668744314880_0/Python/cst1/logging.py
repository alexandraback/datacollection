import sys
import math


class Logging:

    def get_logs(self, trees):
        logs = []
        for tree in trees:
            surrounding = []
            for other in trees:
                if other != tree:
                    surrounding.append(math.atan2(tree[1] - other[1], tree[0] - other[0]))

            if len(surrounding) <= 1:
                logs.append(0)
            else:
                surrounding.sort()

                is_boundary = len(set(surrounding)) == 1
                if not is_boundary:
                    for a1, a2 in zip(surrounding, surrounding[1:] + surrounding[:1]):
                        if a2 < a1:
                            a2 += math.pi * 2
                        if a2 - a1 >= math.pi:
                            is_boundary = True
                            break

                if is_boundary:
                    logs.append(0)
                    continue

                m = len(surrounding)
                for i, a1 in enumerate(surrounding):
                    for j in range(1, m+1):
                        a2 = surrounding[(i + j) % len(surrounding)]
                        if a2 < a1:
                            a2 += math.pi * 2
                        if a2 - a1 >= math.pi:
                            m = min(m, j - 1)
                            break
                logs.append(m)
        return logs

    def solve_case(self, f):
        n = int(f.readline())
        trees = map(lambda _: tuple(map(int, f.readline().split())), range(n))
        return list(self.get_logs(trees))

    def create_report(self, ci, r):
        r = "\n".join(map(str, r)) if not isinstance(r, str) and isinstance(r, (list, tuple)) else str(r)
        return "Case #" + str(ci) + ":\n" + r

    def solve(self, f):
        t = int(f.readline())
        results = []
        for c in range(t):
            results.append(self.solve_case(f))
        return "\n".join(map(lambda c: self.create_report(c[0] + 1, c[1]), enumerate(results)))

    def solve_and_save(self, out, f):
        out.write(self.solve(f))

if __name__ == "__main__":
    l = Logging()

    if len(sys.argv) < 2:
        l.solve_and_save(sys.stdout, sys.stdin)
    else:
        f = open("./in/" + sys.argv[1] + ".in", 'r')
        o = open("./out/" + sys.argv[1] + ".out", 'w')
        l.solve_and_save(o, f)
        f.close()
        o.close()
