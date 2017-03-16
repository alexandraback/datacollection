'''
Created on 12/04/2014

@author: david
'''

f=open("A-small-attempt0.in")

T=int(f.readline())
P=[]
for i in range(T):
    a1 = int(f.readline())
    m1=[]
    for _ in range(4):
        m1.append([int(x) for x in f.readline().strip().split()])
    a2 = int(f.readline())
    m2=[]
    d2={}
    for row in range(4):
        m2.append([int(x) for x in f.readline().strip().split()])
        for col in range(4):
            d2[m2[-1][col]] = row
    P.append((a1,a2,m1,m2,d2))
    
fRes = open("res.txt", "w")
case=0
for a1,a2,m1,m2,d2 in P:
    case+=1
    nums = m1[a1-1]
    
    ss2 = set(m1[a1-1]).intersection(set(m2[a2-1]))
    if len(ss2)<1:
        print("Case #{}: Volunteer cheated!".format(case))
        fRes.write("Case #{}: Volunteer cheated!\n".format(case))
        continue
    
    elif len(ss2)>1:
        print("Case #{}: Bad magician!".format(case))
        fRes.write("Case #{}: Bad magician!\n".format(case))
        continue
    
    for num in m2[a2-1]:
        if num in m1[a1-1]:
            print("Case #{}: {}".format(case,num))
            fRes.write("Case #{}: {}\n".format(case,num))
        
fRes.close()