from itertools import combinations

T = int(raw_input())
for i in range(T):
    R, C, N = [int(a) for a in raw_input().split()]
    res = 4*N
    for p in combinations(range(R*C),N):
        pp = [0]*(R*C)
        for c in p:
            pp[c] = 1
        tab = []
        myr = 0
        x = 0
        y = 0
        c = 0
        for app in pp:
            if y==0:
                tab.append([])
            tab[-1].append(app)
            if app and y and tab[x][y-1]:
                myr += 1
            if app and x and tab[x-1][y]:
                myr += 1
            y += 1
            if y==R:
                y = 0
                x += 1
            c += 1
        if myr < res:
            res = myr
            # print p, tab, myr
    print "Case #"+str(i+1)+": "+str(res)
