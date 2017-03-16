from functools import reduce
from operator import mul
cases = int(input())

#from http://stackoverflow.com/a/147539
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
    return reduce(lcm, args)

for case in range(cases):
    b, n = map(int, input().split(' '))
    initm = list(map(int, input().split(' ')))
    m = [0 for i in range(b)]

    #n %= lcmm(*initm)
    n %= reduce(mul, initm, 1)
    ind = 0

    for i in range(n):
        ind = m.index(min(m))
        m[ind] += initm[ind]
    
    print('Case #{}: {}'.format(case+1, ind+1))
