import sys

def go(p):
    R = int(sys.stdin.readline())
    for r in range(1, 5):
        v = map(int, sys.stdin.readline().split())
        if r != R:
            for c in v:
                p[c] = False
    
def solve(caseno):
    p = [True for i in range(20)]
    go(p)
    go(p)
    C = [x for x in range(1,17) if p[x]]
    sys.stdout.write('Case #%d: ' % caseno)
    if len(C) == 0: print 'Volunteer cheated!'
    elif len(C) == 1: print C[0]
    else: print 'Bad magician!'



T = int(sys.stdin.readline())
for i in range(T):
    solve(i+1)
