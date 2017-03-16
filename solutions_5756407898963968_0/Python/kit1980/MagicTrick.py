def solve(a, xs, b, ys):
    ra = set(xs[a - 1])
    rb = set(ys[b - 1])
    possible = list(ra.intersection(rb))
    if len(possible) == 1:
        return possible[0]
    if len(possible) == 0:
        return "Volunteer cheated!"
    if len(possible) > 1:
        return "Bad magician!"

def do_case(case_num, a, xs, b, ys):
    print "Case #%d: %s" % (case_num, solve(a, xs, b, ys))

def main():
    T = int(raw_input())
    for case_num in range(1, T + 1):
        a = int(raw_input())
        xs = []
        for i in range(4):
            xs.append(map(int, raw_input().split()))
        b = int(raw_input())
        ys = []
        for i in range(4):
            ys.append(map(int, raw_input().split()))
        do_case(case_num, a, xs, b, ys)

if __name__ == "__main__":
    main()
