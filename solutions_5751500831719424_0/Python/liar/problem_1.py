def solve(problem):
    strings = problem

    from itertools import groupby
    def canonical(s):
        return "".join(ch for ch, g in groupby(s))

    def group_lengths(s):
        return [len(list(g)) for ch, g in groupby(s)]

    def moves_count(rs):
        ans = 0
        rs = sorted(rs)
        for i in range(len(rs) // 2):
            ans += rs[-1 - i] - rs[i]
        return ans
    
    canonical_strings = set(canonical(s) for s in strings)
    if len(canonical_strings) != 1:
        return None

    s0 = canonical_strings.pop()
    gs = [group_lengths(s) for s in strings]
    ans = 0
    for i in range(len(s0)):
        ans += moves_count(g[i] for g in gs)
    return ans

def parse_problems():
    import fileinput
    fin = fileinput.input()

    def parse_number(type):
        line = next(fin)
        return type(line)

    def parse_list(type):
        line = next(fin)
        nums = line.split()
        return list(map(type, nums))

    def parse_line():
        line = next(fin)
        return line.strip()

    T = parse_number(int)
    for _ in range(T):
        N = parse_number(int)
        strings = [parse_line() for i in range(N)]
        yield strings

def main():
    for i, p in enumerate(parse_problems()):
        ans = solve(p)
        print("Case #{}: {}".format(i + 1, ans is None and 'Fegla Won' or ans))

if __name__ == '__main__':
    main()