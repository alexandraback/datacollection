import string

L = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

f = open('large.in')
g = open('large.out', 'w')

case = 0
T = int(f.readline()[:-1])

for case in range(T) :
    N = int(f.readline()[:-1])
    P = [int(i) for i in f.readline()[:-1].split(' ')]
    res = ''
    while max(P) > 0 :
        M = P.index(max(P))
        P[M] -= 1
        res += L[M]
        if max(P) == 0 : break
        M = P.index(max(P))
        NP = P[:]
        NP[M] -= 1
        if max(NP) > sum(NP) / 2 :
            pass
        else :
            P[M] -= 1
            res += L[M]
        if max(P) > 0 : res += ' '
        if max(P) > sum(P) / 2 : 1/0
    output = 'Case #' + str(case+1) + ': ' + str(res)
    print(output)
    g.write(output + '\n')

f.close()
g.close()
