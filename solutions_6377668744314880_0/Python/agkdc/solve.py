#! /usr/bin/python
inf = open('input.in')
inp = inf.read().split('\n')
inf.close()

def Solve(*args):
    inf = float('inf')
    n, c = args
    x = [z[0] for z in c]
    y = [z[1] for z in c]
    logs = list()
    if n <= 3:
        logs = [0]*n
    for i in range(n):
        cutoff = inf
        for j in range(n):
            if i == j:
                continue
            if x[i] == x[j]:
                slope = inf
            else:
                slope = float(y[i]-y[j])/(x[i]-x[j])
            if slope != inf:
                lside = len(filter(lambda z:z != i and z != j and (x[i]-x[z])*slope + y[z] > y[i],range(n)))
                rside = len(filter(lambda z:z != i and z != j and (x[i]-x[z])*slope + y[z] < y[i],range(n)))
            else:
                lside = len(filter(lambda z:z != i and z != j and x[z] < x[i],range(n)))
                rside = len(filter(lambda z:z != i and z != j and x[z] > x[i],range(n)))
            cutoff = min(lside, rside, cutoff)
        logs += [cutoff]
    if n <= 3:
        logs = [0]*n
    return '\n%s'%('\n'.join([str(x) for x in logs]))


T = int(inp.pop(0))
outf = open('output','w')
for i in range(T):
    N = int(inp.pop(0))
    C = list()
    for j in range(N):
        C += [[int(x) for x in inp.pop(0).split(' ')]]
    outf.write('Case #%d: %s\n'%(i+1,Solve(N, C)))
outf.close()