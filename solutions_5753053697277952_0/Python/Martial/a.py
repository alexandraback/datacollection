import sys
from collections import defaultdict
# sys.stdin = open('a1.in')
sys.stdin = open('A-small-attempt0.in')
# sys.stdin = open('A-large.in')
sys.stdout = open('out.txt', 'w')


def solve_it(s):
    n = len(s)
    t = sum(s)
    res = []
    while t > 0:
        m = max(s)
        u = [i for i in range(n) if s[i] == m]
        e = chr(65 + u[0])
        s[u[0]] -= 1
        t -= 1
        if len(u) == 2:
            e += chr(65 + u[1])
            s[u[1]] -= 1
            t -= 1
        res.append(e)
    return res


def main():

    n_cases = int(input())
    for test_case in range(1, n_cases + 1):
        n = input()
        s = list(map(int, input().split()))
        print(test_case, file=sys.stderr, end=' ')
        res = solve_it(s)
        print('Case #' + str(test_case) + ':', ' '.join(res))

    print(file=sys.stderr)

if __name__ == '__main__':
    main()
