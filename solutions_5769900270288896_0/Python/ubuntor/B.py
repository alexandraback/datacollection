from itertools import combinations

s = open("in")
n2 = int(s.readline().strip())

o = open("out","w")

for i in range(1,n2+1):
    r,c,n = [int(j) for j in s.readline().strip().split()]
    #r = c = 4
    #n = 8
    ans = r*(c-1) + (r-1)*c
    # blah
    for ii in combinations(range(r*c),n):
        a2 = 0
        for j in range(r):
            for k in range(c-1):
                #print(j*c+k,j*c+k+1)
                if j*c+k in ii and j*c+k+1 in ii:
                    a2 += 1
        #print(a2)
        for j in range(r-1):
            for k in range(c):
                if j*c+k in ii and (j+1)*c+k in ii:
                    a2 += 1
        #print(a2,ii)
        ans = min(ans,a2)
    #print()
    o.write("Case #"+str(i)+": "+str(ans)+"\n")
'''
999899
999891
198999
198001
100891
100001

999899
999001
100999
100001

99999
99001
10099
10001
 1 3
4 6
 9 11
12 14

'''
