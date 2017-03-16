def parse_testcases(infile):
    T = int(infile.readline())
    for _ in range(T):
        yield map(int, infile.readline().split())

def min_unhappiness(R, C, N):
    spaces = R * C
    middle = (R - 2) * (C - 2)

    possibilities = []
    zeros = spaces // 2 + spaces % 2
    twos = 2 if R % 2 == 0 else 0
    threes = R + C - 2 - twos
    fours = middle // 2 
    possibilities.append([(0, zeros), (2, twos), (3, threes), (4, fours)])

    zeros = spaces // 2
    twos = 2 if R % 2 == 0 else 4
    threes = R + C - 2 - twos
    fours = middle // 2 + middle % 2
    possibilities.append([(0, zeros), (2, twos), (3, threes), (4, fours)])

    answers = []
    for pos in possibilities:
        n = N
        h = 0
        while n > 0:
            uh, count = pos.pop(0)
            todo = min(n, count)
            n -= todo
            h += todo * uh
        answers.append(h)

    return min(*answers)

def print_result(case, result):
    print("Case #{}: {}".format(case, result))

def main():
    import sys
    for case, testcase in enumerate(parse_testcases(sys.stdin), 1):
        result = min_unhappiness(*testcase) 
        print_result(case, result)

if __name__ == "__main__":
    main()
