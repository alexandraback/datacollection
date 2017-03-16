from itertools import combinations
import numpy

def begin():
    infile = open('B-small-attempt0 (2).in')
    outfile = open('B-small-attempt0.out', 'w')
    T = int(infile.readline().strip())
    for i in xrange(T):
        r, c, n = map(int, infile.readline().strip().split())
        outfile.write('Case #%d: %d\n' %(i+1, calc(r, c, n)))
    infile.close()
    outfile.close()

def calc_unhappiness(flat_num, r, c, n):
    u = 0
    for idx in range(n):
        curr = flat_num[idx]
        if curr % r != 0 and curr+1 in flat_num:
            #print curr, curr+1, flat_num
            u += 1
        if curr + r <= r * c and curr+r in flat_num:
            #print curr, curr+r
            u += 1
    return u
        

def calc(r, c, n):
    if r*c == n:
        return 2 * r * c - r - c
    min_u = 1e10
    for comb in combinations(range(1, r*c+1), n):
        u = calc_unhappiness(comb, r, c, n)
        if u < min_u:
            min_u = u
            min_u_comb = comb
    return min_u
            

