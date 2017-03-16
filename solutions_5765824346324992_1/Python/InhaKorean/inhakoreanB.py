f_test = ['test.in', 'test.out']
f_small = ['B-small-attempt1.in', 'small.out']
f_large = ['B-large.in', 'large.out']
f_practice_small = ['B-small-practice.in', 'practice_small.out']
f_practice_large = ['B-large-practice.in', 'practice_large.out']

#FILE_NAME = f_test
#FILE_NAME = f_small
FILE_NAME = f_large
#FILE_NAME = f_practice_small
#FILE_NAME = f_practice_large

f = open(FILE_NAME[0], 'r')
o = open(FILE_NAME[1], 'w')

def valid(L, N, time) :
    cnt = 0
    for i in L :
        cnt += time // i + 1
    if cnt >= N : return True
    else : return False
    
def case_result(case) :
    B, N= map(int, f.readline().split())
    L = list(map(int, f.readline().split()))

    left = 0
    right = 10**15
    while left+1 < right :
        mid = (left + right)//2
        if valid(L, N, mid) :
            right = mid
        else :
            left = mid

    for i in L :
        N -= left // i +1
    for i in range(len(L)) :
        if N == 0 : return str(i+1)
        if right % L[i] == 0 : N -= 1
        if N == 0 : return str(i+1)

    print(left, right, N, B)

    return "error"

T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
    
    
