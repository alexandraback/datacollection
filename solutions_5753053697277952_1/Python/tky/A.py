# Google code jam
import numpy as np

alph = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

# read number of cases from stdin    
T = int(input())

for j in range(1,T+1):

    N = int(input())
    P = input().split(' ') # read number of senators
    Senate = ''
    Evac = ''
    for i in range(0,N):
        P[i] = int(P[i])
        Senate += alph[i]*P[i]
    P = np.array(P)
    
    while Senate != '':
        D = np.sort(P)[-2::]
        if (D[1] - D[0])>1:
            out = alph[np.argsort(P)[-1]]*2
        elif (D[1] - D[0])==1:
            out = alph[np.argsort(P)[-1]]
        else:
            if np.sum(P) == np.sum(P[np.argsort(P)[-2::]]):
                out = alph[np.argsort(P)[-1]] + alph[np.argsort(P)[-2]]
            else:
                out = alph[np.argsort(P)[-3]]
                    
        Evac += (out + ' ')
        for ch in out:
            assert(Senate.find(ch) != -1)
            Senate = Senate.replace(ch,'',1)
            P[alph.find(ch)] -= 1
        
    print("Case #{}: {}".format(j,Evac[0:-1]))
