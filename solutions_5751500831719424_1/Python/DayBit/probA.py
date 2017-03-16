'''
Created on 30/04/2014

@author: David Llorens (daybit@gmail.com)
'''

def clean(s):
    res = []
    pre=s[0]
    c=1
    for l in s[1:]:
        if pre!=l:
            res.append((pre, c))
            pre = l
            c = 1
        else:
            c += 1
    res.append((pre, c))

    return ''.join([x[0] for x in res]), [x[1] for x in res]
    
def solve2(vv):
    acu = 0
    for v in vv:
        #print(v)
        m=int(0.5+sum(v)/len(v))
        acu += sum([abs(x-m) for x in v])
        #print(v,m, [abs(x-m) for x in v], sum([abs(x-m) for x in v]))
    return acu
      
def solve(vv):
    acu = 0
    for v in vv:
        m = min(v)
        M = max(v)
        k=10e100
        for n in range(m,M+1):
            kk = sum([abs(e-n) for e in v])
            #if kk>k: break
            k=min(k,kk)
        acu += k
    return acu
  
#fIn=open("A-small-practice.in")
fIn=open("A-large.in")
#fIn=open("A-small-attempt0.in")

T=int(fIn.readline())
P=[]
for i in range(T):
    n=int(fIn.readline())
    ss = []
    for _ in range(n):
        ss.append(fIn.readline().strip())
    P.append((n,ss))
  
case = 0
fRes = open("res.txt", "w")  
for n,ss in P:
    case += 1
    aux = [clean(w) for w in ss]
    if len(set([x[0] for x in aux])) != 1:
        print("Case #{}: {}".format(case, "Fegla Won")) 
        fRes.write("Case #{}: {}\n".format(case, "Fegla Won")) 
        continue
    aux2 = [x[1] for x in aux] 
    aux3=[]
    for i in range(len(aux2[0])):
        yy = []
        for pal in aux2:
            yy.append(pal[i])
        aux3.append(yy)
    #print(aux3)
    
    res = solve(aux3)
    print("Case #{}: {}".format(case, res)) 
    fRes.write("Case #{}: {}\n".format(case, res))  
    #print(n,ss,[clean(w) for w in ss])
    
fRes.close()