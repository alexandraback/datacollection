import sys
from numpy import *


def main():
    T = input()
    for i in range(T): solve(i)


def solve(num):
    guess1 = input()
    cards1 = zeros((4, 4), dtype=int32)
    cards2 = zeros((4, 4), dtype=int32)
    memo = 16 * [0]
    for i in range(4):
        cards1[i] = raw_input().split()
        if i + 1 == guess1:
            for v in cards1[i]:
                memo[v - 1] += 1
    guess2 = input()
    for i in range(4):
        cards2[i] = raw_input().split()
        if i + 1 == guess2:
            for v in cards2[i]:
                memo[v - 1] += 1
    ans = []
    for i in range(16):
        if memo[i] == 2: ans.append(i + 1)
    if len(ans) == 0:
        print "Case #%d: %s" % (num + 1, 'Volunteer cheated!')
    elif len(ans) == 1:
        print "Case #%d: %d" % (num + 1, ans[0])
    else:
        print "Case #%d: %s" % (num + 1, 'Bad magician!')


if __name__ == '__main__':
    main()
