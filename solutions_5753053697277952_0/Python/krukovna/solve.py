import sys


class Solved(Exception):
    pass


def solve(p, a):
    ALL = ['A', 'B', 'C' , 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
    output = []

    while any(a):
        t = ''
        m = max(a)
        j = a.index(m)
        t += ALL[j]
        a[j] -= 1

        if sum(a) != 2:
            m = max(a)
            j = a.index(m)
            t += ALL[j]
            a[j] -= 1

        output.append(t)

    raise Solved(' '.join(output))


if __name__ == '__main__':
    for i in range(int(sys.stdin.readline())):
        p = int(sys.stdin.readline())
        a = list(map(int, sys.stdin.readline().strip().split(' ')))
        try:
            solve(p, a)
        except Solved as e:
            print('Case #{}: {}'.format(i+1, e))
