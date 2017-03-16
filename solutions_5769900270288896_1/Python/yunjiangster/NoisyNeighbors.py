import sys,re,math

def minUnhappy(R,C,T):
    if T <= R * C // 2: return 0
    elif min(R,C) == 1:
        q = (R * C + 1) // 2
        if (R * C % 2 == 1):
            return (T - q) * 2
        else:
            return 1 + (T -q -1) * 2
    elif R%2 == 1 and C%2 == 1:
        
        ret1=None 
        N = T - ( (R * C) // 2 + 1)
        q  = 2 * ( R //2  + C // 2)
        if N <= q: ret1 = 3 * N
        else: ret1 = 3 * q + ( N - q) * 4

        ret2=None
        
        N = T - ( ( R * C ) // 2)
        if N <= 4: ret2 = N * 2
        else:
            N = N - 4
            q = ((R-2)//2 + (C-2)//2) * 2
            if N <= q: ret2 = 4 * 2 + N * 3
            else:
                N = N -q
                ret2 = 4 * 2 + q * 3 + N * 4
        return min(ret1,ret2)

    else:
        T = T - (R * C / 2)
        q = 2
        sides = ( 2 * (R + C) - 4 ) / 2 
        if T <= q: return T * 2
        T = T - q
        q = sides - 2
        if T <= q: return 2 * 2 + T * 3
        else: return 2*2 + q * 3 + (T - q) * 4 
        
            

N = int(sys.stdin.readline().strip('\n'))

for i,line in enumerate(sys.stdin):
    R,C,T = map(int,line.strip('\n').split())
    print 'Case #%d: %d'%(i+1,minUnhappy(R,C,T))
