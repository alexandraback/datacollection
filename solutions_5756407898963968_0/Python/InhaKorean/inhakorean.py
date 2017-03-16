f_small = ['A-small-attempt1.in', 'small.out']
f_large = ['A-large-attempt0.in', 'large.out']

FILE_NAME = f_small
#FILE_NAME = f_large

f = open(FILE_NAME[0], 'r')
o = open(FILE_NAME[1], 'w')

def case_result(case) :
    n = int(f.readline())
    sol = []
    
    for i in range(4) :
        if i == n-1 :
            row1 = [int (i) for i in f.readline().split(' ')]
        else :
            f.readline()        
    
    n = int(f.readline())
    
    for i in range(4) :
        if i == n-1 :
            row2 = [int (i) for i in f.readline().split(' ')]
        else :
            f.readline()        
        
    for i in range(4) :
        for j in range(4) :
            if row1[i] == row2[j] :
                sol.append(row1[i])
    if len(sol) == 0 :
        return "Volunteer cheated!"
    elif len(sol) > 1 :
        return "Bad magician!"
    else :
        return str(sol[0])
            
T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
    
    
