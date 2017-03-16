f_test = ['test.in', 'test.out']
f_small = ['B-small-attempt1.in', 'small.out']
f_large = ['B-large.in', 'large.out']
f_practice_small = ['B-small-practice.in', 'practice_small.out']
f_practice_large = ['B-large-practice.in', 'practice_large.out']

#FILE_NAME = f_test
FILE_NAME = f_small
#FILE_NAME = f_large
#FILE_NAME = f_practice_small
#FILE_NAME = f_practice_large

f = open(FILE_NAME[0], 'r')
o = open(FILE_NAME[1], 'w')

#import sys
#sys.setrecursionlimit(2000)

def gcd(a, b) :
    if b == 0 : return a
    return gcd(b, a%b)
def lcm(L) :
    ret = L[0]
    for i in range(1, len(L)) :
        ret = ret*L[i]//gcd(ret, L[i])
    return ret

def case_result(case) :
    B, N= map(int, f.readline().split())
    L = list(map(int, f.readline().split()))

    lc = lcm(L)
    k = 0
    for i in L :
        k += lc // i

    N %= k
    if N == 0 :
        N += k
    if N <= B : return str(N)
    N -= B
    M = L[:]
    while True :
        for i in range(len(M)) :
            if M[i] == 0 :
                M[i] = L[i]
                N -= 1
                if N == 0 : return str(i+1)
        minum = min(M)
        for i in range(len(M)) :
            M[i] -= minum
    
    return "error"

T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
    
    
