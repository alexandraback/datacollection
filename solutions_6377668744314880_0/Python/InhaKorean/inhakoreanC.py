f_test = ['test.in', 'test.out']
f_small = ['C-small-attempt1.in', 'small.out']
f_large = ['C-large.in', 'large.out']
f_practice_small = ['C-small-practice.in', 'practice_small.out']
f_practice_large = ['C-large-practice.in', 'practice_large.out']

#FILE_NAME = f_test
FILE_NAME = f_small
#FILE_NAME = f_large
#FILE_NAME = f_practice_small
#FILE_NAME = f_practice_large

f = open(FILE_NAME[0], 'r')
o = open(FILE_NAME[1], 'w')

import itertools

def product(a, b) :
    return a[0]*b[1] - a[1]*b[0]

def valid2(L, p1, p2) :
    x = 0
    for i in L :
        if i == p1 or i == p2 : continue
        k = product([p2[0]-p1[0], p2[1]-p1[1]], [i[0] - p1[0], i[1] - p1[1]])
        if k == 0 : continue
        if x * k < 0 : return False
        x = k
    return True

def valid(L, p) :
    if len(L) <= 3 : return True
    cnt = 0
    for j in L :
        if p == j : continue
        if valid2(L, p, j) :
            cnt += 1
    if cnt < 2 :
        return False
            
    return True
   
def case_result(case) :
    #print(case)
    N = int(f.readline())
    L = []
    for i in range(N) :
        L.append(list(map(int, f.readline().split()))+[i])
    ans = [100000] * len(L)
    for i in range(len(L), -1, -1) :
        for l in itertools.combinations(L, i) :
            for p in l :
                if ans[p[2]] > 10000 and valid(l, p) :
                    ans[p[2]] = min(ans[p[2]], len(L) - i)

    return ans
    
T = int(f.readline())
for case in range(1, T+1) :
    ans = case_result(case)
    o.write('Case #'+str(case)+':\n')
    for i in ans :
        o.write(str(i) + '\n')
    #o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
    
    
