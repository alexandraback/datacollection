FILE_PATH = 'C:\\codejam\\'
FILE_NAME = 'A-small-attempt0'

f = open(FILE_PATH + FILE_NAME + '.in', 'r')
o = open(FILE_PATH + FILE_NAME + '.out', 'w')

import queue as Q
def case_result(case) :
    N = int(f.readline())
    P = list(map(int, f.readline().split()))

    ans = ''
    S = sum(P)
    q = Q.PriorityQueue()
    for i in range(N) :
        q.put([-P[i], chr(i + ord('A'))])

    while S > 0 :
        e1 = q.get()
        e2 = q.get()
        
        if S == -(e1[0] + e2[0]) :
            ans += e1[1] + e2[1] + ' '
            e1[0] += 1
            e2[0] += 1
            S -= 2
        else :
            ans += e1[1] + ' '
            e1[0] += 1
            S -= 1

        q.put(e1)
        q.put(e2)
    return ans

T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')
 
f.close()
o.close()
 