t = int(input())
for tc in range(1, t+1):
    n = int(input())
    strlist = []
    for i in range(0, n):
        strlist.append(input())

    countslist = []
    oldcom = ''
    for s in strlist:
        counts = []
        com = ''
        i = 0
        while i < len(s):
            j = i
            while j < len(s) and s[i] == s[j]:
                j += 1
            j -= i
            com += s[i]
            counts.append(j)
            i += j
        if oldcom != '' and com != oldcom:
            break
        oldcom = com
        countslist.append(counts)
    else:
        #countslist contains at every pos the count of the
        #char at the same pos in oldcom
        ysum = 0
        for i in range(0, len(oldcom)):
            ynew = 0
            yold = 1000000
            for j in range(1, 101):
                ynew = sum([abs(x[i]-j) for x in countslist])
                if ynew > yold:
                    break
                yold = ynew
            ysum += yold
        print('Case #%i: %i' % (tc, ysum))
        continue
    print('Case #%i: Fegla Won' % (tc))
    
