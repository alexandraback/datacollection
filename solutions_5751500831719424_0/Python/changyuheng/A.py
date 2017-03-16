# -*- coding: utf-8 -*-

import sys


def get_skeleton(N, strings):
    skeletons = []
    for i in range(N):
        skeleton = [strings[i][0]]
        skeleton += [strings[i][j] for j in range(1, len(strings[i])) if strings[i][j] != strings[i][j-1]]
        skeletons.append(skeleton)
    for i in range(1, N):
        if skeletons[i] != skeletons[i-1]:
            skeletons[0] = []
            break
    return skeletons[0]

def solve():
    N = int(input())
    strings = [input() for _ in range(N)]
    ans = 0

    skeleton = get_skeleton(N, strings)

    if len(skeleton) == 0:
        return 'Fegla Won'

    lengths = []
    for c in skeleton:
        length = dict()
        for i in range(N):
            for j in range(len(strings[i])):
                if strings[i][j] != c:
                    break
            length[j] = length.get(j, 0) + 1
            strings[i] = strings[i][j:] if j < len(strings[i]) else ''
        lengths.append(length)

    for length in lengths:
        ans += min(sum(abs((k - l) * length[l]) for l in length) for k in length)

    return ans

def main():
    T = int(input())
    for i in range(1, T + 1):
        print('Case #{}: {}'.format(i, solve()))

if __name__ == '__main__':
    sys.exit(main())
