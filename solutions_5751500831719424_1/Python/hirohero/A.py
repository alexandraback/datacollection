import math

f = open('A-large.in','r').readlines()
fout = open('A-large.out','w')

test = int(f[0].strip())

line = 1
for ttest in range(test):
    n = int(f[line].strip())
    line += 1
    a = []
    for i in range(n):
        a.append(f[line].strip() + '#')
        line += 1

    mint = 1000000
    setst = []
    for i in range(len(a)):
        setst.append([])
        j = 0
        dem = 1
        while j < len(a[i]) - 1:
            while a[i][j + 1] == a[i][j]:
                j += 1
                dem += 1
            setst[i].append((a[i][j],dem))
            j += 1
            dem = 1

    s = ''
    for i in range(len(setst[0])):
        s = s + setst[0][i][0]

    mint = 1000000000

    ok = True
    for i in range(len(setst)):
        if len(setst[i]) != len(s):
            ok = False
            break
        for j in range(len(setst[i])):
            if setst[i][j][0] != s[j]:
                ok = False
                break
        if ok == False:
            break

    if ok == True:
        dem = 0
        for t in range(len(s)):
            minmin = 1000000000
            for r in range(101):
                temp = 0
                for i in range(len(setst)):
                    temp = temp + math.fabs(setst[i][t][1] - r)
                if temp < minmin: minmin = temp
            dem = dem + minmin
        mint = dem
    else:
        mint = 1000000000
    s = "Case #" + str(ttest + 1) + ': '
    if mint == 1000000000: s = s + 'Fegla Won'
    else: s = s + str(int(mint))
    print >> fout, s
                
fout.close()
