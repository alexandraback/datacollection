#!/usr/bin/env python
# -*- Encoding: utf-8 -*-

from __future__ import print_function, unicode_literals

import sys
import heapq

from collections import defaultdict


def solve(P):
    ans = []
    evacuated = 0
    total = sum(P)
    numleft = total
    numbers = []
    for id, count in enumerate(P):
        heapq.heappush(numbers, (-count, id))

    while numleft > 0:
        largest = list(heapq.nsmallest(2, numbers))
        e = [largest[0]]
        numleft -= 1
        if largest[1][0] != 0 and -largest[1][0] > numleft / 2:
            e.append(largest[1])
            numleft -= 1

        for count, id in e:
            heapq.heapreplace(numbers, (count + 1, id))

        # print([-n[0] for n in numbers])

        ans.append(e)

    return ans

if __name__ == '__main__':
    f = sys.stdin
    T = int(f.readline())

    letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    for t in range(T):
        N = int(f.readline().strip())
        P = map(int, f.readline().strip().split(" "))
        ans = solve(P)
        ans = " ".join(letters[a[0][1]] + (letters[a[1][1]] if len(a) > 1 else "") for a in ans)
        print("Case #{}: {}".format(t + 1, ans))
