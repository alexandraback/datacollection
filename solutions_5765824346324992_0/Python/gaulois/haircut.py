"""
This script may use libraries publicly available at: https://github.com/grokit/dcore.

Does this solution solve:
   Small: ?.
   Big:   ?.
"""

import dcore.gcj_boot as boot

def readProblem(fh):

    b, N = [int(x) for x in fh.readline().strip().split()]
    M = [int(x) for x in fh.readline().strip().split()]

    return (N, M)

def solve(p):
    N, M = p

    n = 1
    B = [0] * len(M)

    mem = {}
    while n <= N:
        mv = min(B)

        if mv != 0:
            for i in range(len(B)):
                B[i] -= mv

        state = tuple(B)
        if mem is not None:
            if state in mem:
                #print('loop')
                lastN = mem[state]
                dist = n - lastN
                remain = N-n
                remain = remain % dist
                #print('jump to', N-remain)
                n = N - remain
                mem = None
                continue
            else:
                mem[state] = n 

        mv = min(B)

        k = B.index(mv)
        B[k] += M[k]
        n += 1

        #print(k)

    return k+1

boot.solve(solve, readProblem, '.*small')
