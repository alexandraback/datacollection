__author__ = 'matjazleonardis'

from string import ascii_uppercase

T = int(raw_input())

for case in range(1,T + 1):
    N = int(raw_input())
    P = [int(s) for s in raw_input().split(" ")]
    total = sum(P)
    MPs = ""
    for x in range(len(P)):
        MPs += P[x] * ascii_uppercase[x]

    moves = []
    if len(MPs) % 2 == 1:
        moves.append(MPs[len(MPs) / 2])
        left = MPs[0:len(MPs)/2]
        left = left[::-1]
        right = MPs[len(MPs)/2 + 1 :]
    else:
        left = MPs[0:len(MPs)/2]
        right = MPs[len(MPs)/2:]
        left = left[::-1]

    #print left,right

    total = 2 * (total / 2)
    for i in range(total / 2):
        moves.append(left[0]+right[0])
        left=left[1:]
        right=right[1:]
    print "Case #"+str(case)+": "+" ".join(moves)








