import itertools

def ltr(i):
    return chr(65+i)

def check(P):
    sumP = sum(P)
    half = sumP/2.
    return all( p<=half for p in P )

if __name__ == "__main__":
    T = int(input())

    for i in range(1,T+1):
        N = int(input())
        P = []
        for p in input().split(" "):
            P.append(int(p))
        
        sol = []
        
        sumP = sum(P)
        while sumP > 0:
            sortP = sorted(P, reverse=True)
            m = sortP[0]
            if P.count(m) == 2:
                inds = [ ind for ind,v in enumerate(P) if v==m ]
                sol.append(inds)
                for ind in inds:
                    P[ind] -= 1
                assert check(P)
            else:
                ind_m = P.index(m)
                sol.append([ind_m,])
                P[ind_m] -= 1
                assert check(P)
            sumP = sum(P)

        # print(sol)
        res = " ".join( [ "".join(map(lambda s: ltr(s), step)) for step in sol ] )
        print("Case #%i: %s" % (i, res))
