import sys, math

PARTIES = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"


def max_party(ps):
    mp = max(ps)
    return [i for i, p in enumerate(ps) if p == mp]


def majority(ps):
    m = float(sum(ps)) / 2.0
    if ps.count(m) > 1:
        return False
    return any([float(p) > m for p in ps])


def solve_case(ps, case_number):
    evacs = []
    while sum(ps) > 0:
        e1 = ps.index(max(ps))
        ps[e1] -= 1
        e2 = ps.index(max(ps))
        ps[e2] -= 1
        if majority(ps):
            ps[e2] += 1
            evacs.append([e1])
            continue
        evacs.append([e1, e2])

    evacs_str = ""
    for evac in evacs:
        evacs_str += (" " + "".join([PARTIES[e] for e in evac]))
    print("Case #%d:%s" % (case_number, evacs_str))


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        r.readline()
        ps = map(int, r.readline().split(' '))

        solve_case(ps, case_number)


if __name__ == '__main__':
    main()
