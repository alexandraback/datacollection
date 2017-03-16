def solve():
    N = int(input())
    P = []
    tot = 0
    inp = [int(x) for x in input().split()]
    for j in range(N):
        P.append((inp[j], chr(ord('A') + j)))
        tot += P[-1][0]
    #print("Tot = {}".format(tot))
    res = []
    while tot > 2:
        P.sort(reverse=True)
        if len(P) == 2 and P[0][0] == P[1][0]:
            tot -= 2
            res.append(P[0][1] + P[1][1])
            n0, p0 = P[0]
            P[0] = n0-1, p0
            n0, p0 = P[1]
            P[1] = n0-1, p0
        else:
            #print(P, tot, res)
            num, party = P[0]
            res.append(party)
            P[0] = (num-1, party)
            tot -= 1
            if P[0][0] == 0:
                P.pop(0)
    #print("After, P = {}".format(P))
    #print("tot = {}".format(tot))
    assert(tot == 2 or tot == 0)
    if tot == 2:
       for (num, _) in P:
           assert(num == 1)
       res.append(''.join(b for (a, b) in P))
    return res
    
        
n_cases = int(input())

for i in range(n_cases):
    print("Case #{}: {}".format(i+1, ' '.join(solve())))
