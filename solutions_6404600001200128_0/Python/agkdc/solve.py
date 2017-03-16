#! /usr/bin/python
inf = open('input.in')
inp = inf.read().split('\n')
inf.close()

def Solve(*args):
    m = args
    y = 0
    z = 0
    intervals = []
    for i in range(len(m)-1):
        if m[i+1] < m[i]:
            y += m[i] - m[i+1]
    for i in range(len(m)-1):
        if m[i+1] < m[i]:
            intervals += [m[i]-m[i+1]]
        else:
            intervals += [m[i]]
    for i in range(len(m)-1):
        if m[i+1] < m[i]:
            if m[i]-m[i+1] == max(intervals):
                z += m[i]-m[i+1]
            else:
                z += m[i]
        else:
            z += m[i]
    if len(list(set(m))) == 1:
        z = 0
    return '%d %d'%(y,z)

T = int(inp.pop(0))
outf = open('output','w')
for i in range(T):
    N = int(inp.pop(0))
    M = [int(x) for x in inp.pop(0).split(' ')]
    outf.write('Case #%d: %s\n'%(i+1,Solve(*M)))
outf.close()