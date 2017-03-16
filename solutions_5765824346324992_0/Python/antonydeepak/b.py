from functools import reduce

def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcmm(args):
    return reduce(lcm, args)

def gcdd(args):
    return reduce(gcd,args)

T = int(input())
for tc in range(1,T + 1):
    B,N = list(map(int,input().split()))
    M = list(map(int,input().split()))

    common=gcdd(M)
    R_M=[v//common for v in M]
    reset_interval=lcmm(M)
    batch=0
    for v in M:
        batch += reset_interval//v
    k= (N%batch)
    k=batch if k==0 else k
    '''print("l",reset_interval)
    print("b",batch)
    print("R",R_M)
    print("k",k)'''
    if k <= B:
        print("Case #{0}: {1}".format(tc,k))
        continue
    n=k-B
    #possibles=[]
    sec=1
    while n > 0:
        for i,v in enumerate(R_M):
            if sec%v==0:
                n-=1
                if n == 0:
                    print("Case #{0}: {1}".format(tc,i+1))
                    break
        sec+=1
            #possibles.append(i)
    '''ans=min(possibles)+1
    print(n,possibles)
    print("Case #{0}: {1}".format(tc,ans))'''