__author__ = 'walid'

filename = 'A-small-attempt0'
# dirname = '/Users/walid/Downloads/'
dirname = 'D:\\Downloads\\'
inFile = open(dirname+filename+'.in', 'r')
outFile = open(dirname+filename+'.out', 'w')

T = (int)(inFile.readline())

def process(ms, t):
    ds = [y-x for (x, y) in zip(ms, ms[1:])]
    d1s = [min(d, 0) for d in ds]
    r1 = -sum(d1s)
    rate = -min(d1s)
    r2 = sum(min(m, rate) for m in ms[0:-1])


    outFile.write('Case #{}: {} {}\n'.format(t, r1, r2))


for t in range(1, T+1):
    N = int(inFile.readline())
    ms = [int(x) for x in inFile.readline().strip().split(' ')]
    process(ms, t)
