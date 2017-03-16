import sys
from functools import *
from itertools import *
import heapq


def solve(parties):
    steps = []
    sump = sum(imap(lambda x: x[0], parties))
    heapq.heapify(parties)
    while sump != 0:
        if sump == -3:
            larg = heapq.heappop(parties)
            sump += 1
            larg = (larg[0] + 1, larg[1])
            steps.append(larg[1])
            if larg[0] != 0:
                heapq.heappush(parties, larg)
        else:
            [larg, sec_larg] = [heapq.heappop(parties), heapq.heappop(parties)]
            if abs(larg[0] - sec_larg[0]) >= 2:
                sump += 2
                larg = (larg[0] + 2, larg[1])
                steps.append(2 * larg[1])
            else:
                sump += 2
                steps.append(larg[1] + sec_larg[1])
                larg = (larg[0] + 1, larg[1])
                sec_larg = (sec_larg[0] + 1, sec_larg[1])
            if larg[0] != 0:
                heapq.heappush(parties, larg)
            if sec_larg[0] != 0:
                heapq.heappush(parties, sec_larg)
    return " ".join(steps)


if __name__ == '__main__':
    t = int(raw_input())
    for i in range(0, t):
        N = int(raw_input())
        parties = []
        for j, n in enumerate(raw_input().split()):
            parties.append((-int(n), chr(ord("A") + j)))
        print("Case #{0}: {1}".format(i + 1, solve(parties)))
