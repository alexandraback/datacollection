__author__ = 'walid'

filename = 'B-small-attempt1'
# filename = 'test'
# dirname = '/Users/walid/Downloads/'
dirname = 'D:\\Downloads\\'
inFile = open(dirname+filename+'.in', 'r')
outFile = open(dirname+filename+'.out', 'w')

T = (int)(inFile.readline())

def process(Ms, N, it):
    # use bisection to figure out the time my barber is free
    t1 = -1
    t2 = (N+1)*max(Ms)
    while(t2-t1>1):
        t = int((t2 + t1)/2)
        Ns = [int(t/M) + 1 for M in Ms]
        print(t, Ns)
        if(sum(Ns) < N):
            t1 = t
        else:
            t2 = t
    print(t1, t2)
    # t2 should be the time I get a haircut
    started = sum(int(t2/M)+1 for M in Ms)
    available = [i+1 for (i, M) in enumerate(Ms) if (t2 % M == 0)]
    print('started: {}'.format(started))
    print('available: {}'.format(available))
    r = available[(N-1-started)]

    outFile.write('Case #{}: {}\n'.format(it, r))
    return r

for t in range(1, T+1):
    (B, N) = (int(x) for x in inFile.readline().strip().split(' '))
    Ms = [int(x) for x in inFile.readline().strip().split(' ')]
    process(Ms, N, t)


