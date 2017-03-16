import os
import math
import copy
import sys

os.chdir('C:/Python33/2014')
f = open('A-small-attempt0.in','r')
fo = open('A-small.out','w')
T = int(f.readline())
for ite in range(T):
    r1 = int(f.readline())
    for i in range(4):
        temp = str.split(f.readline())
        if i==r1-1:
            rec1 = temp
    r2 = int(f.readline())
    for i in range(4):
        temp = str.split(f.readline())
        if i==r2-1:
            rec2 = temp
    print(rec1,rec2)
    rec = list(set(rec1) & set(rec2))
    print(rec)
    fo.write('Case #')
    fo.write(str(ite+1))
    fo.write(': ')
    if len(rec) == 0:
        fo.write('Volunteer cheated!')
    elif len(rec) == 1:
        fo.write(rec[0])
    else:
        fo.write('Bad magician!')
    fo.write('\n')
fo.close()

