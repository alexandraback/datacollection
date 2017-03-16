import sys

from string import uppercase

def get_top_indices(Ps):
    m = 0
    top = []
    for i,p in enumerate(Ps):
        if p > m:
            top = [i]
            m = p
        elif p == m:
            top.append(i)
    return top, m
        

def solve(Ps):
    commands = []
    
    while True:
        top_indices, count = get_top_indices(Ps)

        if count == 0:
            return ' '.join(commands)

        if len(top_indices) % 2 == 1:
            i = top_indices.pop()
            commands.append(uppercase[i])
            Ps[i] -= 1
        else:
            i1 = top_indices.pop()
            i2 = top_indices.pop()
            commands.append(uppercase[i2] + uppercase[i1])
            Ps[i1] -= 1
            Ps[i2] -= 1
            
def main():
    T = int(sys.stdin.readline().strip())

    for i in xrange(T):
        N = int(sys.stdin.readline().strip())
        Ps = map(int, sys.stdin.readline().strip().split())
        assert len(Ps) == N
        ans = solve(Ps)
        print 'Case #%s: %s' % (i+1, ans)

if __name__ == '__main__':
    main()
