t = int(input())  
for i in range(1, t + 1):
    n = int(input())
    vals = [int(si) for si in input().split()]
    
    abccap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    #print(max(vals))
    res = ''
    maxv = max(vals)
    while maxv:
        #print(vals)
        if vals.count(maxv) > 1 and ((len(vals) - vals.count(0)) > 3 or (len(vals) - vals.count(0)) == 2):
            maxi = vals.index(maxv)
            maxj = vals.index(maxv, maxi + 1)
            vals[maxi] -= 1
            vals[maxj] -= 1
            res += abccap[maxi] + abccap[maxj] + ' '
        else:
            maxi = vals.index(maxv)
            vals[maxi] -= 1
            res += abccap[maxi] + ' '
        maxv = max(vals)

    print('Case #{}: {}'.format(i, res))
