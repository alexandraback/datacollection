t = int(raw_input())
tt = 1
while tt <= t:
    n = int(raw_input())
    s = []
    for i in range(n):
        s.append(raw_input())
    S = 0
    f = False
    inds = [0]*n
    while True:
        br = False
        for i in range(n):
            if inds[i] == len(s[i]):
                br = True
                break
        if br:
            break
        sss = set([])
        for i in range(n):
            sss.add(s[i][inds[i]])
        if len(sss) > 1:
            f = True
            break
        l = s[0][inds[0]]
        thing = [0]*n
        for i in range(n):
            while inds[i] < len(s[i]) and s[i][inds[i]] == l:
                thing[i] += 1
                inds[i] += 1
        mmm = 90019001
        for i in range(1,200):
            mm = 0
            # move thing to i
            for j in thing:
                mm += abs(j-i)
            mmm = min(mmm,mm)
        S += mmm
        #print l,aa,bb,s
    sss = set([])
    for i in range(n):
        sss.add(s[i][-1])
    if f or len(sss) > 1:
        print "Case #{0}: Fegla Won".format(tt)
    else:
        print "Case #{0}: {1}".format(tt,S)
    tt += 1