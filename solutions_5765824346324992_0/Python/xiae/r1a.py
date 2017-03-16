from time import sleep
from fractions import gcd

def a (fname):
    fin = open(fname + ".in")
    lines = fin.readlines()
    T = int(lines[0])
    fout = open(fname + ".out", "w")
    for t in range(1, T+1):
        N = int(lines[2*t-1])
        m = [int(s) for s in lines[2*t].split()]
        fout.write("Case #" + str(t) + ": " + str(a_mushrooms1(N, m)) + " " + str(a_mushrooms2(N, m)) + "\n")

def a_mushrooms1(N, m):
    eaten = 0
    curr = m[0]
    for mi in m:
        if mi < curr:
            eaten = eaten + curr - mi
        curr = mi
    return eaten

def a_mushrooms2(N, m):
    eaten = 0
    slope = max(max([m[i-1] - m[i] for i in range(1, N)]), 0)
    for i in range(N-1):
        if m[i] < slope:
            eaten = eaten + m[i]
        if m[i] >= slope:
            eaten = eaten + slope
    return (eaten)



def b (fname):
    fin = open(fname + ".in")
    lines = fin.readlines()
    T = int(lines[0])
    fout = open(fname + ".out", "w")
    for t in range(1, T+1):
        print(t)
        line = [int(i) for i in lines[2*t - 1].split()]
        B = line[0]
        N = line[1]
        m = [int(s) for s in lines[2*t].split()]
        fout.write("Case #" + str(t) + ": " + str(b_barber(B, N, m)) + "\n")

def lcm (factors):
    curr = factors[0]
    for i in range(1, len(factors)):
        curr = abs(factors[i] * curr)/gcd(factors[i], curr) if factors[i] and curr else 0
    return curr

def b_barber(B, N, m):
    t = [0 for i in range(B)]
    n = 0
    b = 0
    cycle_length = lcm(m)
    custs_per_cycle = sum([cycle_length/m[i] for i in range(B)])
    N_short = N % custs_per_cycle
    if N_short == 0:
        N_short = custs_per_cycle
    while n < N_short:
        while 0 not in t:
            t = [max(t[i] - 1, 0) for i in range(B)]
        n = n + 1
        b = t.index(0)
        t[b] = m[b]
    return (b + 1)


def c (fname):
    fin = open(fname + ".in")
    lines = fin.readlines()
    T = int(lines[0])
    fout = open(fname + ".out", "w")
    for t in range(1, T+1):
        l1 = lines[2*t-1].split()
        l = l1[0]
        x = l1[1]
        qs = lines[2*t].strip()
        fout.write("Case #" + str(t) + ": " + c_answer(l, x, qs) + "\n")
