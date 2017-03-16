import math
import numpy as np


def fname(s, s1):


    return plan




fin = open('A-small-attempt2.in', 'r')
fout = open('A12.out', 'w')

alist = fin.read().splitlines()
t = int(alist[0])
fileindex = 1
for i in range(1, t+1):
    s = int(alist[fileindex])
    s1 = [int(j) for j in alist[fileindex+1].split(' ')]
    # n = int(alist[fileindex])
    # s = alist[fileindex+1: fileindex+n+1]
    # fileindex += n

    fileindex += 2
    plan = ''
    p = sum(s1)
    while sum(s1) > 0:
        p += 1
        j = s1.index(max(s1))
        plan += chr(65 + j)
        if p % 2 == 0:
            plan += ' '
        s1[j] -= 1
    #print("Case #{}: {}".format(i, fname(s, s1)))
    fout.write('Case #{}: {}\n'.format(i, plan))
