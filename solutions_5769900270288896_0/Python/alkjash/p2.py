#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p2.out", "w")

T = int(fin.readline())

def search(r, c, n, l):
    if n == 0:
        return 0
    elif n > r * c:
        return 100000000
    
    ans = [0 for x in xrange(2**c)]
    for x in xrange(2**c):
        new_l = map(int, list(bin(x)[2:].zfill(c)))
        if sum(new_l) > n:
            ans[x] = 100000000
            continue
        for i in xrange(1, len(new_l)):
            ans[x] += new_l[i] * new_l[i-1]
        for i in xrange(len(new_l)):
            ans[x] += new_l[i] * l[i]
        ans[x] += search(r-1, c, n - sum(new_l), new_l) 
    return min(ans)

for i in xrange(T):
    print i
    R, C, N = map(int, fin.readline().split())
    R, C = max(R, C), min(R, C)
    fout.write("Case #" + str(i+1) + ": " + str(search(R, C, N, [0 for i in xrange(C)])) + "\n")
