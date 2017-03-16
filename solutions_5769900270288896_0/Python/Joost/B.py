#! /usr/bin/env python

from itertools import permutations

fname = 'B-small-attempt0'

fin = open(fname+'.in', 'r')
fout = open(fname+'.out', 'w')

def e(R, C, x, y, w):
    if x < 0 or y < 0 or x >= R or y >= C:
        return False
    return w[x*C + y]

def num(R, C, w):
    n = 0
    for i in range(R):
        for j in range(C):
            if w[i*C + j]:
                if e(R, C, i-1, j, w):
                    n += 1
                if e(R, C, i, j-1, w):
                    n += 1
                if e(R, C, i+1, j, w):
                    n += 1
                if e(R, C, i, j+1, w):
                    n += 1
    return n


def solve(fin):
    R, C, N = list(map(int, fin.readline().split()))
    n = 100000000
    for i in range(2 ** (R*C)):
        a = [x == '1' for x in bin(i)[2:]]
        if sum(a) != N:
            continue
        a = [False] * (R*C-len(a)) + a
        n = min(n, num(R, C, a)//2)
    return n

T = int(fin.readline())
for i in range(1, T+1):
    print(i)
    fout.write("Case #"+str(i)+": "+str(solve(fin))+"\n")
fout.close()
fin.close()
