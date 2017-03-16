import sys
import numpy as np




def solve(case, N, M):
    y = 0
    prev = M[0]
    for m in M:
        if m < prev:
            y += prev - m
        prev = m

    max_speed = 0
    prev = M[0]
    for m in M:
        if m < prev:
            max_speed = max(max_speed, prev - m)
        prev = m
    z = 0
    if max_speed != 0:
        for m in M[:-1]:
            z += min(m, max_speed)

    print N, M, y, z
    return (y, z)



filename_in = sys.argv[1]
filename_out = filename_in.partition('.')[0] + '.out'
with open(filename_out, "w") as fout:
    with open(filename_in, "r") as fin:
        T = int(fin.readline())
        for case in range(1, T+1):
            N = int(fin.readline())
            M = [int(x) for x in fin.readline().split()]
            solution = solve(case, N, M)
            print >> fout, "Case #%i: %i %i" % (case, solution[0], solution[1])
