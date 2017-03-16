from time import sleep
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
        d = int(lines[2*t-1])
        p = tuple([int(p_i) for p_i in lines[2*t].split()])
        fout.write("Case #" + str(t) + ": " + str(minutes(d, p)) + "\n")
        print(t)

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
