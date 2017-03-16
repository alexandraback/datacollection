f_test = ['test.in', 'test.out']
f_small = ['A-small-attempt0.in', 'small.out']
f_large = ['A-large.in', 'large.out']
f_practice_small = ['A-small-practice.in', 'practice_small.out']
f_practice_large = ['A-large-practice.in', 'practice_large.out']

#FILE_NAME = f_test
FILE_NAME = f_small
#FILE_NAME = f_large
#FILE_NAME = f_practice_small
#FILE_NAME = f_practice_large

f = open(FILE_NAME[0], 'r')
o = open(FILE_NAME[1], 'w')

def solve1(N, L) :
    ret = 0
    for i in range(1, N) :
        ret += max(0, L[i-1] - L[i])
    return ret

def solve2(N, L) :
    v = 0
    ret = 0
    for i in range(1, N) :
        v = max(v, L[i-1] - L[i])

    for i in range(N-1) :
        ret += min(v, L[i])
    return ret

def case_result(case) :
    N = int(f.readline())
    L = list(map(int, f.readline().split()))
    return str(solve1(N, L)) + ' ' + str(solve2(N, L))

T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
