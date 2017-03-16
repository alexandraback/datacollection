'''
Created on 12/04/2014

@author: david
'''

#f=open("exampleB.txt")
f=open("B-small-attempt4.in")
#f=open("B-large.in")

T=int(f.readline())
P=[]
for i in range(T):
    p = [int(n) for n in f.readline().split()]
    P.append(p)

def pp(r,c,n):
    mi = min(r,c)
    ma = max(r,c)
    
    ne = 2
    nl = 2*(r//2-1 + c//2+1)
    ve = 2
    vl = 3 
    
    m = r*c//2
    if n<=m: return 0
    d = n-m
    if d<=ne: return d*ve
    d2 = n-m-ne
    if d2<=nl: return ne*ve + d2*vl
    d3 = n-m-ne-nl
    return ne*ve + nl*vl + d3*4
    
def pi(p,i,n):
    #print("kkk",p,i)
    ne = 2 if i!=1 else 1
    nl = (i-2 + p-2) if i!=1 else p//2-1
    ve = 2 if i!=1 else 1
    vl = 3 if i!=1 else 2
        
    m = p*i//2
    if n<=m: return 0
    d = n-m
    if d<=ne: return d*ve
    d2 = n-m-ne
    if d2<=nl: return ne*ve + d2*vl
    d3 = n-m-ne-nl
    return ne*ve + nl*vl + d3*4
    
def ii(r,c, n):
    if r==1 and c==1: return 0
    m = (r*c)//2+1
    if n<=m: return 0
    if n-1==m: return 3
    
    mi = min(r,c)
    ma = max(r,c)
    ne = 4 if mi!=1 else 2
    nl = (2*(r//2-1 + c//2-1)) if mi!=1 else (ma-2)//2
    ve = 2 if mi!=1 else 1
    vl = 3 if mi!=1 else 2
    
    m = (r*c)//2
    d = n-m
    if d<=ne: return d*ve
    d2 = n-m-ne
    if d2<=nl: return ne*ve + d2*vl
    d3 = n-m-ne-nl
    return ne*ve + nl*vl + d3*4
      
def solve(r,c,n):
    if n==0: return 0
    rp = r%2==0
    cp = c%2==0
    if rp and cp: return pp(r,c,n)
    if (not rp) and cp: return pi(c,r,n)
    if rp and (not cp): return pi(r,c,n)
    return ii(r,c,n)
       
fRes = open("res.txt", "w")
case=0
for r,c,n in P:
    print(r,c,n)
    case+=1
    sol = solve(r,c,n)
    print("Case #{}: {}".format(case,sol))
    fRes.write("Case #{}: {}\n".format(case,sol))
        
fRes.close()