def solve():
    N = int(raw_input())

    P = [int(i) for i in raw_input().split()]
    
    ret = ""

    while (sum(P) > 0):
        z = P.index(max(P))
        P[z] -= 1
        ret += "%c" % (65 + z)
    
        # Check majority
        if max(P) > sum(P)/2:
            z = P.index(max(P))
            P[z] -= 1
            ret += "%c" % (65 + z)

        ret += " "
        
    return ret 

T = int(raw_input())
for t in range(1,T+1):
    print("Case #%d: %s" % (t,solve()))
