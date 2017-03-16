INPUT_FILE = "A-small-attempt0.in"


def solve_case(case):
    sol = []
    case_split = case.split(' ')
    l = [[int(case_split[i]), chr(i+ord('A'))] for i in range(len(case_split))]
    l.sort(reverse=True)
    while l[0][0] > 0:
        if len(l) < 2 or l[0][0] > l[1][0]:
            sol.append(l[0][1])
            l[0][0] -= 1
        elif len(l) < 3 or l[1][0] > l[2][0]: # l[0][0] == l[1][0] && l[1][0] > l[2][0]
            sol.append(l[0][1]+l[1][1])
            l[0][0] -= 1
            l[1][0] -= 1
        else:  # l[0][0] == l[1][0] == l[2][0]
            sol.append(l[0][1])
            l[0][0] -= 1
        l.sort(reverse=True)

    return ' '.join(sol)


def main():
    with open(INPUT_FILE) as fh:
        cases = [l.rstrip() for l in fh.readlines()[2::2]]

    sol = ''
    for i in range(len(cases)):
        sol += "Case #{}: {}\n".format(i+1, solve_case(cases[i]))

    with open(INPUT_FILE.replace('.in', '.out'), 'w') as fh:
        fh.write(sol)

if __name__ == '__main__':
    main()
