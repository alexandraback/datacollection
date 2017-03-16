import sys
import math
import os


def nex(t=int):
    return t(sys.stdin.readline().strip())


def main():
    t = nex()
    for case in range(1, t + 1):
        ans = 0

        n = int(sys.stdin.readline().strip())

        l = [int(s) for s in sys.stdin.readline().split()]

        maxd = 0
        a1 = 0
        for i in range(1, len(l)):
            maxd = max(maxd, l[i-1] - l[i])
            a1 += max(0, l[i-1] - l[i])

        a2 = 0
        for i in range(1, len(l)):
            a2 += min(maxd, l[i-1])


        sys.stdout.write('Case #%s: %s %s\n' % (case, a1, a2))


if __name__ == '__main__':
    main()
