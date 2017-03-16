
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b / gcd(a, b)

def solve(N,B):
    M=reduce(lcm,B)
    m=sum(M//b for b in B)
    N%=m
    if N==0:
        N=m
    R=[0]*len(B)
    while True:
        dt=min(R)
        R=[r-dt for r in R]
        for i,b in enumerate(B):
            if R[i]==0:
                N-=1
                if N==0:
                    return i+1
                R[i]=b

for tc in range(input()):
    _,N=map(int,raw_input().split())
    B=map(int,raw_input().split())
    print 'Case #{}: {}'.format(tc+1,solve(N,B))
