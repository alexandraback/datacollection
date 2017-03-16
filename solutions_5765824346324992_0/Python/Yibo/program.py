#!/usr/bin/python2.7

from operator import itemgetter

f = open('input.txt', 'r')
T = int(f.readline())

def getN(t, M_arr):
    count = 0
    for mi in M_arr:
        count += (t / mi + 1)
    return count

def solve(M_arr, N):
    leftT = 0
    rightT = pow(10, 14)
    leftN = getN(leftT, M_arr)
    rightN = getN(rightT, M_arr)
    midN = 0

    while rightT - leftT > 1:
        midT = (leftT + rightT) / 2
        midN = getN(midT, M_arr)
        if midN < N:
            leftT = midT
            leftN = midN
        else:
            rightT = midT
            rightN = midN

    T = leftT

    if T == 0:
        N_left = N - 1
        for i, r in enumerate(M_arr):
            if r == 1:
                if N_left == 0:
                    print i + 1
                    return
                N_left -= 1

    N_before = N - getN(T, M_arr) - 1
    assert N_before >= 0
#    assert N > getN(T, M_arr)
#    assert N <= getN(T + 1, M_arr)

    remains = [None] * len(M_arr)
    for index in range(len(M_arr)):
        mi = M_arr[index]
        remains[index] = T % mi
    for i, r in enumerate(remains):
        if r == M_arr[i] - 1:
            if N_before == 0:
                print i + 1
                return
            N_before -= 1

    raise ValueError('N_before: ' + str(N_before))

for t in range(T):
    B, N = f.readline().rstrip().split(' ')
    B = int(B)
    N = int(N)

    M_arr = map(int, f.readline().rstrip().split(' '))
    assert B == len(M_arr)

    print "Case #" + str(t + 1) + ":",
    solve(M_arr, N)

