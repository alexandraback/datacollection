import sys

def gcd(num1,num2):
    if num2 == 0: 
        return num1 
    else: 
        return gcd(num2,num1%num2)

def lcm(num1,num2): 
    tmp = gcd(num1,num2) 
    return num1*num2/tmp 

def cmp_func(x, y):
    if x[0] != y[0]:
        return x[0] - y[0]
    return x[1] - y[1]
T = int(sys.stdin.readline())
for t in range(T):
    B, N = [int(x) for x in sys.stdin.readline().split()]
    M = [int(x) for x in sys.stdin.readline().split()]

    
    curr_lcm = 1
    for m in M:
        curr_lcm = lcm(curr_lcm, m)
    

    period_N = 0
    for m in M:
        period_N += curr_lcm / m

    
    N = N % period_N
    if N == 0: N = period_N

    serving_list = []
    
    for i, m in enumerate(M):
        i = i+1
        time = 0
        while time <= curr_lcm:
            serving_list.append((time, i))
            time += m

    serving_list = sorted(serving_list, cmp=cmp_func)
        

     


    
    
    print "Case #%d: %d" % (t+1, serving_list[N-1][1])




