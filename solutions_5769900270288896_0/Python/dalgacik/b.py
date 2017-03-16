import pdb
import numpy as np

def score_1d(row):
    row = row.ravel()
    N = len(row)
    res = 0
    for i in xrange(N-1):
        if row[i]*row[i+1]:
            res += 1
    return res

def unhappiness_score(M):
    m, n = M.shape
    unhap_score = 0
    for i in xrange(m):
        row = M[i,:]
        unhap_score += score_1d(row)
    for i in xrange(n):
        column = M[:,i]
        unhap_score += score_1d(column)
    return unhap_score
    
    

def solve_case(R, C, N):
    num_dists = 2**(R*C)
    result = np.inf
    for dist in xrange(num_dists):
        dist = bin(dist)
        dist = dist[2:]
        dist = (R*C - len(dist)) * '0' + dist
        dist = [1 if x == '1' else 0 for x in dist]
        dist = np.array(dist)
        try:
            dist = dist.reshape(R,C)
        except:
            pdb.set_trace()
        if dist.sum() != N:
            continue
        cur_score = unhappiness_score(dist)
        if cur_score < result:
            result = cur_score
        
    return  str(result)

filename = 'B-small-attempt0'



with open(filename+'.in') as filein,\
open(filename + '.out', 'wb') as fileout:
    T = int(filein.next().strip())
    for i in xrange(T):
        case_num = i + 1
        x = filein.next().strip().split()
        R, C, N = map(int, x)
        res = solve_case(R, C, N)
        fileout.write("Case #" + str(case_num) + ": " + str(res) + "\n")
        