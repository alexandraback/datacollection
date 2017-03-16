from __future__ import division

import os
import sys
import itertools
name = 'B-small-attempt0'

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

        

def format(out):
    return out

def solve(*args, **kwargs):
    return format(_solve(*args, **kwargs))

#print(solve(2,3,6),7)
#print(solve(4,1,2),0)
#print(solve(3,3,8),8)
#print(solve(5,2,0),0)
#print(solve(4,4,8),0)
#print(solve(4,4,9),2)
#print(solve(4,4,10),4)
#print(solve(4,4,11),7)
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
    








