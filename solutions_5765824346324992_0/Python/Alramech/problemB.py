import math
import functools
f = open("B-small-attempt1.in", "r")
#f = open("B-large.in", "r")
#f = open("b1.txt", "r")
num_cases = int(f.readline())
cases = []

def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""   
    return functools.reduce(lcm, args)




for c in range(num_cases):
    cases.append((f.readline(), f.readline()))
    
def processCase(case):
    tok1 = case[0].split()
    B = int(tok1[0])
    N = int(tok1[1])
    tok = case[1].split()
    Mk = [int(x) for x in tok]
    return [B, N, Mk]
    
  
    
def processTest(test):
    mk = test[2]
    N = test[1]
    B = test[0]
    barbers = mk[:]
    #N = N - B
    ind = 0
    lcl = barbers[0]
    for k in barbers[1:]:
        lcl = lcm(k, lcl)
    print(lcl)
    perTick = [lcl / x for x in barbers]
    print(perTick)
    print(sum(perTick))
    if N > sum(perTick):
        print(N)
        N = N%sum(perTick)
        print(N, 'a')
        N += sum(perTick)
    if N-B > 0:
        N = N-B
    print(N)
    while N > 0:
        #print(N)
        if 0 not in barbers:
            g2 = min(barbers)
            barbers = [x-g2 for x in barbers]
        else:
            ind = barbers.index(0)
            barbers[ind] = mk[ind]
            N -= 1
    return int(ind+1)
cnum = 1
g = open("B-out.txt", "w")
#g = open("B-large-out.txt", "w")
#print(cases)
for c in cases:
    print(processCase(c))
    value = processTest(processCase(c))
    #print("Case #{}: {} {}".format(cnum, value[0], value[1]))
    #g.write("Case #{}: {} {}\n".format(cnum, value[0], value[1]))
    print("Case #{}: {}".format(cnum, value))
    g.write("Case #{}: {}\n".format(cnum, value))
    #print(cnum)
    cnum+=1