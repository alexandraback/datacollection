import sys

with open(sys.argv[1], 'r') as f:
    for k in range(int(f.readline())):
        N = int(f.readline())
        alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        Ps = [(int(c), alphabet[i]) for i,c in enumerate(f.readline().split())]
        #rint Ps
        Ps.sort(reverse=True)
        res = []
        while Ps[0][0] > Ps[1][0]:
            res.append(Ps[0][1])
            Ps[0] = (Ps[0][0]-1, Ps[0][1])
        i = len(Ps) -1
        while i > 1:
            for j in range(Ps[i][0]):
                res.append(Ps[i][1])
            i -= 1
        for j in range(Ps[0][0]):
            res.append(Ps[0][1]+Ps[1][1])
        print 'Case #{}: {}'.format(k+1, ' '.join(res))
