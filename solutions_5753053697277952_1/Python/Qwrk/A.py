import numpy as np
import string

letters = string.ascii_uppercase


def solve(p):
    result = ''
    while np.sum(p) != 0:
        p1 = np.argmax(p)
        p[p1] -= 1
        result += letters[p1]
        if np.max(p) * 2 > np.sum(p):
            p2 = np.argmax(p)
            p[p2] -= 1
            result += letters[p2]
        result += ' '
    return result


def main():
    t = int(input())
    for case in range(1, t + 1):
        n = int(input())
        p = np.array(list(map(int, input().split())))
        print('Case #%d: %s' % (case, solve(p)))

if __name__ == '__main__':
    main()