#!/usr/bin/python

#
# get brute force points...
#
from itertools import combinations

def NN(): return tuple(map(int, raw_input().split()))

T = NN()[0]
for t in range(1, T + 1):
    R, C, N = NN()
    #print R, C, N
   
    answer =  R * C * 4
    for rooms in combinations(range(R*C), N):
        house = [[False] * C for i in range(R)]
        for r in rooms:
            house[r/C][r%C] = True

        w = 0
        for i in range(R):
            for j in range(C):
                if house[i][j]:
                    if i + 1 < R and house[i+1][j]:
                        w += 1
                    if j + 1 < C and house[i][j+1]:
                        w += 1
                    if w > answer:
                        break

            if w > answer:
                break

        answer = min(answer, w)

    print "Case #%d: %s" % (t, answer)

