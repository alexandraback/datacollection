from numpy import median
filename = 'A-small-attempt0'
ans = False
with open(filename + '.in', 'r') as dat, open(filename + '.out', '+w') as output:
    _T = int(dat.readline())
    for _t in range(_T):
        _N = int(dat.readline().strip('\n'))        
        k = []
        r = []
        ans = 0
        f = 1
        for _n in range(_N):            
            d = []
            s = dat.readline().strip('\n')
            d = [[s[0], 1]]
            for i in s[1:]:
                if d[-1][0] == i:
                    d[-1][1] += 1
                else:
                    d.append([i, 1])
            k.append(d)
            r.append(len(d))
            if r[-1] != r[0] or sum([k[-1][i][0] != k[0][i][0] for i in range(len(d))]):
                ans = 0
                f = 0
                break
        if f:
            for i in range(r[0]):
                v = median([k[j][i][1] for j in range(len(k))])
                ans += sum([abs(k[j][i][1] - v) for j in range(len(k))])
                

            ans = int(ans)
        else: 
            ans = 'Fegla Won'
        output.write('Case #' + str(_t + 1) + ': ' + str(ans) + '\n')
      