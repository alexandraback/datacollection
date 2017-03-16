#! /usr/bin/python
from fractions import gcd

def lcm(*numbers):
    def lcm(a, b):
        return (a * b) / gcd(a, b)
    return reduce(lcm, numbers, 1)

inf = open('input.in')
inp = inf.read().split('\n')
inf.close()

def Solve(*args):
    b, m, n = args
    round_time = lcm(*m)
    round_costumer = sum([round_time/x for x in m])
    n = (n % round_costumer)
    if n == 0:
        for i in range(1,b+1):
            if m[b-i] == min(m):
                return b-i
    if n < b:
        return n-1
    remaining_time = m[:]
    while n > 0:
        for barber in range(b):
            if remaining_time[barber] == min(remaining_time):
                break
        barber_time = remaining_time[barber]
        remaining_time = [x-barber_time for x in remaining_time]
        remaining_time[barber] = m[barber]
        n -= 1
    return barber


T = int(inp.pop(0))
outf = open('output','w')
for i in range(T):
    B, N = [int(x) for x in inp.pop(0).split(' ')]
    M = [int(x) for x in inp.pop(0).split(' ')]
    outf.write('Case #%d: %s\n'%(i+1,Solve(B,M,N)+1))
outf.close()