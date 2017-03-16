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

def case_result(case) :
    N = int(f.readline())
    if N == 2 :
        n1 = f.readline()[:-1]
        n2 = f.readline()[:-1]

        c1 = [n1[0]]
        d1 = [1]
        for i in range(0, len(n1)) :
            if c1[-1] == n1[i] :
                d1[-1] +=1
                continue
            else :
                c1.append(n1[i])
                d1.append(1)
        c2 = [n2[0]]
        d2 = [1]
        for i in range(0, len(n2)) :
            if c2[-1] == n2[i] :
                d2[-1] +=1
                continue
            else :
                c2.append(n2[i])
                d2.append(1)
        print(c2)
        if len(c1) != len(c2) : return "Fegla Won"
        for i in range(len(c1)) :
            if c1[i] != c2[i] : return "Fegla Won"

        res = 0
        for i in range(len(d1)) :
            res += abs(d1[i] - d2[i])
        return str(res)
        
    return "error" 

T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
    
    
