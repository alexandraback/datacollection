f_test = ['test.in', 'test.out']
f_small = ['A-small-attempt0.in', 'small.out']
f_large = ['A-large.in', 'large.out']
f_practice_small = ['A-small-practice.in', 'practice_small.out']
f_practice_large = ['A-large-practice.in', 'practice_large.out']

#FILE_NAME = f_test
#FILE_NAME = f_small
FILE_NAME = f_large
#FILE_NAME = f_practice_small
#FILE_NAME = f_practice_large

f = open(FILE_NAME[0], 'r')
o = open(FILE_NAME[1], 'w')

def case_result(case) :
    N = int(f.readline())
    n = [f.readline() for i in range(N)]
    c = [[n[i][0]] for i in range(N)]
    d = [[0] for i in range(N)]
    
    for i in range(N) :
        for j in range(len(n[i])) :
            if c[i][-1] == n[i][j] :
                d[i][-1] += 1
                continue
            else :
                c[i].append(n[i][j])
                d[i].append(1)
    for i in range(N) :
        if len(c[0]) != len(c[i]) : return "Fegla Won"
        for j in range(len(c[0])) :
            if c[0][j] != c[i][j] : return "Fegla Won"
    res = 0

    for j in range(len(c[0])) :
        temp = [0]*100
        for i in range(N) :
            for k in range(1, 101) :
                temp[k-1] += abs(d[i][j] - k)

        res += min(temp)
    
    return str(res)

T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
    
    
