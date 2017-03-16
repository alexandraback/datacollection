'''
Created on 15 de abr. de 2016

@author: Marcelo
'''
def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

def isMayority(P):
    if max(P) > sum(P)-max(P):
        return True
    else:
        return False

def solve(P, N):
    
    ABC = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
    s = sum(P)
    r = []
    rs = ''
    z = [0 for i in range(N)]
    #while z != N:
    for i in range(s*2):
        if(P == z):
            return r
        m = max(P)
        mi =  [h for h, j in enumerate(P) if j == m]
        
        
        if rs == '':
            P[mi[0]] = P[mi[0]]-1
            
            rs = ABC[mi[0]]
            
        else:
            P[mi[0]] = P[mi[0]]-1
            if isMayority(P) :
                
                r.append(rs)
                P[mi[0]] = P[mi[0]] +1
                rs = ''
            else:
                rs = rs + ABC[mi[0]]
                r.append(rs)
                rs = ''
        #print P, r
    return r

_T = readint()
for t in range(1, _T+1):

    N = readint()
    P = [int(x) for x in raw_input().split(" ")]
    
    r = solve(P, N)
    
        
    print 'Case #%i:'%(t), ' '.join(r)