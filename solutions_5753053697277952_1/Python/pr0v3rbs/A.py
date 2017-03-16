def Get(N, PN, P, isAvg):
    result = ''
    if isAvg == False:
        t = P[0]
        for i in P:
            if t != i:
                t = i
                break
        if t == P[0]:
            isAvg = True

    if isAvg == False :
        m = 0
        tI = 0
        for i in range(N):
            if P[i] > m:
                m = P[i]
                tI = i
        P[tI] -= 1
        PN -= 1
        result += chr(ord('A') + tI)
        '''
        m = P[0]
        for i in P:
            m = min(m, i)

        for i in range(N):
            if P[i] > m:
                PN -= 1
                P[i] -= 1
                result += chr(ord('A') + i)
            if len(result) == 2:
                break

            if P[i] > m:
                PN -= 1
                P[i] -= 1
                result += chr(ord('A') + i)
            if len(result) == 2:
                break
        '''
    else :
        l = []
        t = ''
        while PN != 0:
            for i in range(N):
                if P[i] > 0:
                    PN -= 1
                    P[i] -= 1
                    t += chr(ord('A') + i)
                if (len(t) == 1 and PN == 2) or len(t) == 2:
                    l.append(t)
                    t = ''
        if t :
            l.append(t)
        for i in l:
            result += i + " "
        result = result[:-1]

    return N, PN, P, isAvg, result


for test in range(1, input() + 1):
    N = input()
    P = [int(i) for i in raw_input().split()]
    PN = sum(P)
    isAvg = False

    r = "Case #" + str(test) + ":"

    while PN != 0:
        N, PN, P, isAvg, t = Get(N, PN, P, isAvg)
        r += " " + t
    print r
