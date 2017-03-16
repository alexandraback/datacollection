from sys import stdin
import sys
if len(sys.argv) > 1:
    sys.stdout = open(sys.argv[1], 'w')

def flip(b):
    if b == '1': return '0'
    if b == '0': return '1'
    assert False
            
def each_case(N, mushroom):
    y = sum(mushroom[n]-mushroom[n+1] for n in xrange(N-1) if mushroom[n] > mushroom[n+1])
    max_drop = max(mushroom[n]-mushroom[n+1] for n in xrange(N-1))
    z = sum(min(m, max_drop) for m in mushroom[:-1])
    return '{} {}'.format(y, z)

T = int(stdin.readline())
for t in xrange(1,T+1):
    N = int(stdin.readline())
    mushroom = map(int, stdin.readline().split()[:N])
    print 'Case #{}: {}'.format(t, each_case(N, mushroom))
