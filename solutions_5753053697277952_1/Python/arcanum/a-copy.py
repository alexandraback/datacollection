from math import *

def rl(l): return range(len(l))



f = open("a-large.out", mode='w')

T = int(input())

for nt in range(1, T+1):
    N = int(input())
    
    v = []

    cnt = 1 # 1
    for i in range(cnt):
        cline = list(map(int, input().split()))
        if len(cline) == 1: cline = cline[0]
        v.append(cline)
        v = v[0]

    ans = ""

    # we can't leave one senator by themself

    while sum(v): 
        mind = [0]
        for i in range(1, len(v)):
            if v[i] > v[mind[0]]: # easy error with >=
                mind = [i]
            elif v[i] == v[mind[0]]:
                mind.append(i)

        toremove =[]
        if sum(v) == 3:
            toremove = [mind[0]]
        else:
            if len(mind) >=2:
                toremove=mind[:2]
            else:
                toremove=[mind[0]]


        for ind in toremove:
            v[ind] -= 1
        toadd = "".join(str(chr(ord("A")+i)) for i in toremove)
        ans += " "+toadd

        
                
                
        

    #print(v)


    
    towrite = "Case #"+str(nt)+":"+str(ans)+'\n' # no space after colon
    f.write(towrite)
    print(towrite, end="")
    
f.close()

'''
4
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1

2
26
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
25
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
'''
