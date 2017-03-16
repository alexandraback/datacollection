def gcd(a,b):
    while b:
        a,b = b,a%b
    return a
def lcm(a,b):
    return a*b//gcd(a,b)
def lcmm(*args):
    return reduce(lcm,args)
def solve(a1,n):
    if n<=len(a1):
        return n
    a = list(a1)
    #print (a)
    num = len(a)
    while True:
        i = min(a)
        for j in range(len(a)):
            a[j]-=i
            if a[j]==0:
                num+=1
                if num==n:
                    return j+1
                a[j]+=a1[j]
        
    

for t in range(int(input())):
    (b,n) = [int(s) for s in input().strip().split(" ")]
    a = [int(s) for s in input().strip().split(" ")]
    reset_time = 1
    for i in a:
        reset_time = lcm(reset_time,i)
    num = [reset_time//s for s in a]
    total = 0
    for i in num:
        total+=i
    n=n%total
    if n==0:
        n = total
    print("Case #{0}: {1}".format(t+1,solve(a,n)))
