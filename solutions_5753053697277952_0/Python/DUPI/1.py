import os
os.chdir('/Users/mac/OneDrive/competitions/codejam 2016/round2_c/1')
import numpy as np
import math
from collections import defaultdict
import string



##extra_need
def isValid(l):
    if  sum([x[1] for x in l]) == 0:
        return True
    return float(max([x[1] for x in l])) / sum([x[1] for x in l]) <= 0.5
    

def getW(l):
    l = [[string.ascii_uppercase[i], int(x)] for i,x in enumerate(l)]
    r = []
    while sum([x[1] for x in l]) > 0:
        l.sort(key=lambda x: x[1], reverse=True)
        l[0][1] -= 1
        if isValid(l):
            r.append(l[0][0])
            continue
        l[0][1] += 1
        
        l[0][1] -= 2
        if l[0][1]>=0 and isValid(l):
            r.append(l[0][0] * 2)
            continue
        l[0][1] += 2
        
        l[1][1] -= 1
        l[0][1] -= 1
        if l[1][1]>=0 and isValid(l):
            r.append(l[0][0] + l[1][0])
            continue
        l[1][1] += 1
        l[0][1] += 1
        
        l[1][1] -= 1
        if l[1][1]>=0 and isValid(l):
            r.append(l[1][0])
            continue
        
        l[1][1] -= 1
        if l[1][1]>=0 and isValid(l):
            r.append(l[1][0] * 2)
            continue
        else:
            raise Exception('error')
            
    return ' '.join(r)
        
        




##read test.in
test_f = open('./tests/A-small-attempt0.in.txt')
out_f = open('./tests/A-small-attempt0.out.txt', 'w+')
test_num = None
test_case_num = 1
current_rcs = []

n_parties = None
for line in test_f:
    if test_num == None:
        test_num = int(line)
    elif n_parties == None:
        n_parties = int(line)
    else:
        n_parties = None
        s = line.strip() 
        l = line.split()
        T = getW(l)
        #print '{}, {}, {}'.format(max_s, audiences, extra_need) 
        out_f.write('Case #{}: {}\n'.format(test_case_num, T))
        test_case_num += 1
        
test_f.close()
out_f.close()