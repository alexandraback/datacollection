import functools
import copy

def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcmm(l): 
    x = 1
    for e in l:
        x = lcm(x, e)
    return x

for case in range(int(input())):
    b, n = map(int, input().split())
    mstart = list(map(int, input().split()))
    l = lcmm(mstart)
    #print(l)
    num_pp_one_loop = 0
    for e in mstart:
        num_pp_one_loop += (l // e)
    left = n % num_pp_one_loop
    if left == 0:
        ms = copy.deepcopy(mstart)
        while num_pp_one_loop > 0:
            emin = min(ms)
            for i, e in enumerate(ms):
                if e == emin:
                    num_pp_one_loop -= 1
                    if num_pp_one_loop == 0:
                        print("Case #{}: {}".format(case + 1, i + 1))
                ms[i] -= emin
                if ms[i] == 0:
                    ms[i] = mstart[i]
    else:
        n = left
        n -= b
        if n < 0:
            print("Case #{}: {}".format(case + 1, left))
            continue

        ms = copy.deepcopy(mstart)
        while n > 0:
            emin = min(ms)
            for i, e in enumerate(ms):
                if e == emin:
                    n -= 1
                    if n == 0:
                        print("Case #{}: {}".format(case + 1, i + 1))
                ms[i] -= emin
                if ms[i] == 0:
                    ms[i] = mstart[i]

