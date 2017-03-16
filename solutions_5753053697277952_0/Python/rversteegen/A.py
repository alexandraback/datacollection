def ints():
    return [int(x) for x in raw_input().strip().split()]

T = input()
for t in range(T):
    N, = ints()
    P = ints()

    S = sum(P)
    P = [[p,idx] for idx,p in enumerate(P)]
    P = sorted(P)

    soln = []
    while S > 0:
        def char(x):
            P[x][0] -= 1
            return (chr(ord('A') + P[x][1]))

        if S == 3:
            soln.append(char(-1))
            S -= 1

        else:
            soln.append(char(-1) + char(-2))
            S -= 2

        P.sort()
        assert P[-1][0] * 2 <= S

    print "Case #%d: %s" % (t+1, " ".join(soln))
