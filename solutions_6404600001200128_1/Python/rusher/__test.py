n = int(input())
for nnn in range(n):
    mins = int(input())
    mus = map(int, raw_input().split())
    const = 0
    re1 = 0
    re2 = 0
    for i in range(mins - 1):
        if mus[i] > mus[i+1]:
            re1 += mus[i] - mus[i+1]
            const = max(const, (mus[i] - mus[i+1])/10.0)
    for m in range(mins - 1):
        if mus[m] <= const * 10:
            re2 += mus[m] 
        else: 
            re2 += const * 10
    print 'Case #%d'%(nnn+1) + ': ', int(re1), int(re2) 