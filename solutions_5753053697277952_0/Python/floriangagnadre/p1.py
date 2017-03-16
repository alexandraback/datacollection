def get_cases(filename):
    with open(filename, 'r') as f:
        T = int(f.readline())
        cases = []
        for t in range(T):
            N = int(f.readline())
            S = [int(x) for x in f.readline().split()]
            case = [[S[i],chr(i+65)] for i in range(N)]
            cases.append((N, case))
        return T, cases

def get_plan(N, S):
    assert(N>1)
    assert(N<27)
    res = []
    while (len(S) > 2):
        S.sort(reverse=True)
        res.append(S[0][1])
        S[0][0] -= 1
        if S[0][0] == 0:
            S = S[1:]
    while S[0][0] > 0:
        res.append(S[0][1] + S[1][1])
        S[0][0] -= 1
        S[1][0] -= 1
    return res

def b_print(res, T, filename):
    with open(filename, 'w') as f:
        for t in range(T):
            f.write("Case #{0}: {1}\n".format(t+1, ' '.join(res[t])))

if __name__ == '__main__':
    filename = 'A-small-attempt0.in'
    T, cases = get_cases(filename)
    res = [get_plan(case[0], case[1]) for case in cases]
    b_print(res, T, 'A-small.out')