def gcd(a,b):
    while b:
        a,b = b,a%b
    return a

def lcm(a,b):
    return a*b // gcd(a,b)

def lcm_list(l):
    lcm_of_list = l[0]
    len_of_list = len(l)
    for i in range(1,len_of_list):
        lcm_of_list = lcm(lcm_of_list,l[i])
    return lcm_of_list

T = int(input())
for test_case in range(T):
    B,N = [int(x) for x in input().split()]
    M = [int(x) for x in input().split()]
    cycle_time = lcm_list(M)
    cycle_cuttable = 0
    for m in M:
        cycle_cuttable += cycle_time//m
    time = 0
    time += ((N-1)//cycle_cuttable)*cycle_time
    N = (N-1)%cycle_cuttable+1
    Bt = [0 for i in range(B)]
    ans = 0
    while N>0:
        bt_min = min(Bt)
        for i in range(B):
            Bt[i] -= bt_min
            if Bt[i]==0:
                Bt[i] = M[i]
                N -= 1
                if N == 0:
                    ans = i+1
    print('Case #'+str(test_case+1)+': '+str(ans))
