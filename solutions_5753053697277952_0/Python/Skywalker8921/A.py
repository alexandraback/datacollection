import sys,math

def printerr(*a,**b):
    print(*a,file=sys.stderr,**b)

def is_valid_setup(P):
    pm = max(P)
    ps = sum(P)
    return 2*pm <= ps

partys="ABCDEFGHJIJKLMNOPQRSTUVWYZ"

def main(N,P):
    PP = P.copy()
    res = []
    ps = sum(PP)
    while (ps > 0):
        NZ = [i for i in range(N) if PP[i] > 0]
        NNZ = len(NZ)
        pmi = max(range(N),key=lambda x : PP[x])
        pm = PP[pmi]
        #printerr(pm,NNZ,ps)
        equals = (pm*NNZ == ps)
        if not equals:
            res.append(partys[pmi])
            PP[pmi] -= 1
        elif (NNZ == 2):
            res.append(partys[NZ[0]]+partys[NZ[1]])
            PP[NZ[0]] -= 1
            PP[NZ[1]] -= 1
        else:
            res.append(partys[NZ[0]])
            PP[NZ[0]] -= 1
        #printerr(res,PP)
        ps = sum(PP)
        assert is_valid_setup(PP)
    return res
            
            
if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        N = int(input())
        P = [int(i) for i in input().split()]

        ## Processing
        res = main(N,P)

        ## Output
        print("Case #{}: {}".format(c+1," ".join(res)))


