from __future__ import division

import os
#import sys
#from math import log, floor, ceil, sqrt, pi
#from random import randint, choice, shuffle
#from collections import defaultdict
from heapq import heappush, heappop, heapify
#inf = 10**20

name = 'A-small-attempt0.in'

def _solve(parties):
    #n = len(parties)
    parties = list(parties)
    sm = sum(parties)
    hparties = [(-num, i) for i, num in enumerate(parties)]
    heapify(hparties)
    evac = []
    while sm>0:
        mx1, i1 = heappop(hparties)
        mx2, i2 = heappop(hparties)
        mx1 = -mx1
        mx2 = -mx2
        assert(mx1 <= 2*sm)
        if mx1 == 1 and mx2 == 1 and sm == 3:
            evac.append((i1,))
            heappush(hparties, (-mx2, i2))
            sm -= 1
            continue
        if mx1 == 1 and mx2 == 1 and sm != 3:
            evac.append((i1, i2))
            sm -= 2
            continue
        assert(mx1 >= 2)
        assert(mx2 >= 1)
        if 2*mx2 <= sm - 2:
            mx1 -= 2
            heappush(hparties, (-mx2, i2))
            if mx1 > 0:
                heappush(hparties, (-mx1, i1))
            evac.append((i1, i1))
            sm -= 2
            continue
        else:
            mx1 -= 1
            mx2 -= 1
            if mx1 > 0:
                heappush(hparties, (-mx1, i1))
            if mx2 > 0:
                heappush(hparties, (-mx2, i2))
            evac.append((i1, i2))
            sm -= 2
            continue

    return evac

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def solve(*args, **kwargs):
    res = _solve(*args, **kwargs)
    evac = []
    for t in res:
        evac.append(''.join(alphabet[l] for l in t))
    return ' '.join(evac)

inp_path = '/home/mama/Downloads/%s'%name
if os.path.isfile(inp_path):
    os.system('mv %s .' % inp_path)
inp_file = open(name)
out_file = open('%s.out'%name, 'w')
cases = int(inp_file.readline())
for caseno in range(cases):
    n = int(inp_file.readline().strip())
    parties = tuple(map(int, inp_file.readline().split()))
    res = solve(parties)
    print(caseno, res)
    print('---')
    out_file.write('Case #%d: %s\n'%((caseno+1), res))
    out_file.flush()
out_file.close()









