__author__ = 'horban'


def canonize(s):
    def sp(can, s):
        if not s:
            return can
        else:
            c = s[0]
            if can and c == can[-1]:
                return sp(can, s[1:])
            else:
                return sp(can + [s[0]], s[1:])

    return ''.join(sp([], s))


def mul_arr(s):
    def sp(can, muls, s):
        if not s:
            return muls
        else:
            c = s[0]
            if can and c == can[-1]:
                muls[-1] += 1
                return sp(can, muls, s[1:])
            else:
                muls.append(1)
                return sp(can + [s[0]], muls, s[1:])

    return sp([], [], s)


def min_moves_to_eq(nums):
    s = min(nums)
    best = 1000000000000
    e = max(nums)
    for i in range(s, e + 1):
        r = 0
        for n in nums:
            r += abs(i - n)
        best = min(best, r)
    return best


def solve_case(strings):
    canonical = [canonize(s) for s in strings]
    if not all(canonical[0] == c for c in canonical):
        return 'Fegla Won'

    resuslt = 0
    muarrs = [mul_arr(s) for s in strings]
    print muarrs
    for cat in range(len(muarrs[0])):
        x = min_moves_to_eq([muarrs[i][cat]
                             for i in range(len(muarrs))])
        resuslt += x

    return str(resuslt)

import sys
infname = sys.argv[1]
with open(infname) as inf:
    with open(infname.replace('.in', '.out'), 'w') as outf:
        T = int(inf.readline())
        for t in range(1, T+1):
            n = int(inf.readline())
            strs = [inf.readline().strip() for _ in range(n)]
            ans = solve_case(strs)


            outf.write('Case #{}: {}\n'.format(t, ans))
