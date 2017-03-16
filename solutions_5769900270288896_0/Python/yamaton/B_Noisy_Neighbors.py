#!/usr/bin/env python3
"""
Google Code Jam
2015 Round 1B

Problem B. Noisy Neighbors

@author: yamaton
@date: 2015-05-02
"""
import itertools
import collections


def bruteforce(R, C, N):
    def unhappiness(dic):
        tmp1 = sum(1 for i, j in zip(range(R - 1), range(1, R))
                     for c in range(C)
                     if dic[(i, c)] == dic[(j, c)] == True)
        tmp2 = sum(1 for i, j in zip(range(C - 1), range(1, C))
                     for r in range(R)
                     if dic[(r, i)] == dic[(r, j)] == True)
        return tmp1 + tmp2


    positions = itertools.combinations([(i, j) for i in range(R) for j in range(C)], N)
    results = []
    for choice in positions:
        d = collections.defaultdict(bool)
        for (i, j)  in choice:
            d[(i, j)] = True
        score = unhappiness(d)
        results.append(score)                    
        # print(score, dict(d))

    return min(results)



if __name__ == '__main__':
    for i in range(int(input())):
        print("Case #%d: " % (i + 1), end='')
        R, C, N = [int(s) for s in input().strip().split()]
        result = bruteforce(R, C, N)
        print(result)
