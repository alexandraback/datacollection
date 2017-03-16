import sys


def solve(nums):
    sol = []
    zipped = zip(map(lambda x: chr(x + ord('A')), range(26)), nums)
    ordered = sorted(zipped, key=lambda x: x[1], reverse=True)
    # print ordered
    (a, x), (b, y) = ordered[0], ordered[1]
    diff = x - y
    if diff % 2 != 0:
        sol.append(a)
    for _ in range(diff / 2):
        sol.append(a + a)

    for (p, i) in ordered[2:]:
        if i % 2 != 0:
            sol.append(p)
        for _ in range(i / 2):
            sol.append(p + p)
    for _ in range(y):
        sol.append(a + b)
    return ' '.join(sol)


def main():
    lines = map(lambda s: s.strip(), sys.stdin.readlines()[2:])
    case = 1
    i = 0
    while i < len(lines):
        nums = map(int, lines[i].split())
        sol = solve(nums)
        print "Case #%d: %s" % (case, sol)
        case += 1
        i += 2

if __name__ == '__main__':
    main()
