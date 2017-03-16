from collections import defaultdict

T = int(raw_input().strip())

for t in range(T):
    N = int(raw_input().strip())
    A = map(int,raw_input().strip().split(' '))
    P = map(lambda x: chr(x + 65), range(26))
    k = range(N)
    tot = sum(A)
    ans = []
    while tot > 0:
        ks = sorted(k,key = lambda x:A[x], reverse = True)
        if A[ks[1]] <= (tot-2)/2:
            A[ks[0]] -= 2
            ans.append(P[ks[0]]*2)
            tot -= 2
        elif A[ks[0]] == 1 and (tot %2) == 1:
            A[ks[0]] -= 1
            ans.append(P[ks[0]])
            tot -= 1
        else:
            A[ks[0]] -= 1
            A[ks[1]] -= 1
            tot -= 2
            ans.append(P[ks[0]] + P[ks[1]])
    print "Case #%d: %s" % (t+1, ' '.join(ans))