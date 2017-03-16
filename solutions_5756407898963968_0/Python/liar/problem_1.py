import fileinput

def read_int(fin):
    return int(next(fin))

def read_list(fin):
    line = next(fin)
    nums = line.split()
    return list(map(int, nums))

def problems(fin):
    T = read_int(fin)
    for _ in range(T):
        r1 = read_int(fin)
        t1 = [read_list(fin) for r in range(4)]
        r2 = read_int(fin)
        t2 = [read_list(fin) for r in range(4)]
        assert(all(len(row) == 4 for row in t1))
        assert(all(len(row) == 4 for row in t2))
        yield r1, t1, r2, t2

def solve(problem):
    r1, t1, r2, t2 = problem
    s1, s2 = set(t1[r1 - 1]), set(t2[r2 - 1])
    s = s1 & s2
    if len(s) > 1:
        return "Bad magician!"
    try:
        return s.pop()
    except KeyError:
        return "Volunteer cheated!"

def main():
    for i, p in enumerate(problems(fileinput.input())):
        ans = solve(p)
        print("Case #{}: {}".format(i + 1, ans))

if __name__ == '__main__':
    main()