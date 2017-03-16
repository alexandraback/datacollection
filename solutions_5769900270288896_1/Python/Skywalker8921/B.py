import sys,math

def val_total(v0,v1,v2,v3,N):
    if N <= v0:
        res = 0
    elif N <= v0+v1:
        res = N-v0
    elif N <= v0+v1+v2:
        res = v1 + 2*(N-v0-v1)
    elif N <= v0+v1+v2+v3:
        res = v1 + 2*v2 + 3*(N-v0-v1-v2)
    else:
        res = v1 + 2*v2 + 3*v3 + 4*(N-v0-v1-v2-v3)
    print("val_total({},{},{},{},{})={}".format(v0,v1,v2,v3,N,res),
          file=sys.stderr)
    return res
    

def main_large(R,C,N):
    if R%2 != 0 and C%2 == 0:
        return main_large(C,R,N)
    if C != 1 and R == 1:
        return main_large(C,R,N)
    if C == 1:
        if R%2 == 0:
            v0 = R//2
            v1 = 1
            v2 = R - ((R//2) +1)
            v3 = 0
        else:
            v0 = (R+1)//2
            v1 = 0
            v2 = R - ((R+1)//2)
            v3 = 0
        return val_total(v0,v1,v2,v3,N)
    elif R%2 == 0 :
        v0 = C*(R//2)
        v1 = 0
        v2 = 2
        v3 = C-2 + 2*((R//2) -1)
        return val_total(v0,v1,v2,v3,N)
    else: # R odd, C odd, both != 1
        v01 = (R//2)*(C//2) + ((R+1)//2)*((C+1)//2)
        v11 = 0
        v21 = 0
        v31 = 2*(R//2) + 2*(C//2)
        val1 = val_total(v01,v11,v21,v31,N)
        
        v02 = ((R+1)//2)*(C//2) + (R//2)*((C+1)//2)
        v12 = 0
        v22 = 4
        v32 = 2*((R+1)//2) + 2*((C+1)//2) - 8
        val2 = val_total(v02,v12,v22,v32,N)

        return min(val1,val2)


def main_small(R,C,N):
    if R > C:
        return main_small(C,R,N)
    elif R == 1:
        if C % 2 == 0:
            if N <= C//2 :
                return 0
            else:
                k = N - (C//2 + 1)
                return 2*k+1
        else:
            if N <= (C+1)//2:
                return 0
            else:
                k = N - (C+1)//2
                return 2*k
    elif R == 2:
        if N <= C:
            return 0
        elif N <= C+2:
            k = N-C
            return 2*k
        else:
            k = N-(C+2)
            return 4 + 3*k
    elif R == 3:
        if C == 3:
            if N <= 5:
                return 0
            elif N == 6:
                return 3
            elif N == 7:
                return 6
            elif N == 8:
                return 8
            else:
                return 12
        elif C == 4:
            if N <= 6:
                return 0
            elif N <= 8:
                return 2*(N-6)
            elif N == 9:
                return 8
            elif N == 10:
                return 10
            elif N == 11:
                return 13
            else:
                return 17
        else: # C == 5
            if N <= 8:
                return 0
            elif N <= 10:
                return 3*(N-8)
            elif N <= 11:
                return 8
            elif N <= 13:
                return 3*(N-11)+8
            elif N == 14:
                return 18
            else:
                return 22
    elif R == 4: ## C == 4
        if N <= 8:
            return 0
        elif N <= 10:
            return 2*(N-8)
        elif N <= 14:
            return 4+3*(N-10)
        else:
            return 16+4*(N-14)
    else:
        return None
    
if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        R,C,N = [int(i) for i in input().split()]
        ## Processing
        print("Case #{}:".format(c+1),file=sys.stderr)
        res = main_large(R,C,N)
        ## Output
        print("Case #{}: {}".format(c+1,res))
        print("Case #{}: {}".format(c+1,res),file=sys.stderr)

