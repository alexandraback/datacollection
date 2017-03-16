from __future__ import division

import os
import sys
import itertools
import random
name = 'B-large'

def _solve(r, c, n):
    pos = list(itertools.product(range(r), range(c)))

    def unhappy(comb):
        res = 0
        for x,y in comb:
            res += sum((1 if (x+dx,y+dy) in comb else 0) for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)])
        assert res % 2 == 0
        return res // 2

    minu = 10**20
    for comb in itertools.combinations(pos, n):
        minu = min(minu, unhappy(comb))
    return minu

def __solve(r, c, n):
    #if min(r,c) == 1:

    res = 10**20
    for rem in [0,1]:
        nums = [0,0,0,0,0]
        nn = n
        for x in range(c):
            for y in range(r):
                if (x+y)%2 == rem:
                    nums[0] += 1
                elif x in [0, c-1] and y in [0, r-1]:
                    if min(r,c)!=1:
                        nums[2] += 1
                    else:
                        nums[1] += 1
                elif x in [0, c-1] or y in [0, r-1]:
                    if min(r,c)!=1:
                        nums[3] += 1
                    else:
                        nums[2] += 1
                else: nums[4] += 1
        
        unhappy = 0
        for penalty, num in enumerate(nums):
            tbd = min(num, nn)
            unhappy += penalty * tbd
            nn -= tbd
            if n == 0:
                break
        res = min(res, unhappy)
    return res


def format(out):
    return out

def solve(*args, **kwargs):
    return format(__solve(*args, **kwargs))

#print(__solve(2,3,6),7)
#print(__solve(4,1,2),0)
#print(__solve(3,3,8),8)
#print(__solve(5,2,0),0)
#print(__solve(4,4,8),0)
#print(__solve(4,4,9),2)
#print(__solve(4,4,10),4)
#print(__solve(4,4,11),7)
#for _ in range(10000):
#    r = random.randint(0,10)
#    c = random.randint(0,10)
#    n = random.randint(0, r*c)
#    if r*c>28:
#        continue
#    #if r<2 or c<2:
#    #    continue
#    s1 = _solve(r,c,n)
#    s2 = __solve(r,c,n)
#    print(s1, s2, s1==s2)
#    if s1!=s2:
#        print(r,c,n)
#        raise Exception('invariant violation')
#sys.exit(0)

os.system('cp /home/mama/Downloads/%s.in .'%name)
os.system('rm /home/mama/Downloads/%s*.in'%name)
lines = open('%s.in'%name).readlines()
output = open('%s.out'%name, 'w')
cases = int(lines[0])
curline = 1
for caseno in range(cases):
    inp = tuple(int(x) for x in lines[curline].split())
    curline += 1
    output.write('Case #%d: %s\n'%((caseno+1), str(solve(*inp))))
    output.flush()
output.close()
    








