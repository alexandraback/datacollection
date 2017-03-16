
import sys

def getint():
    return int(sys.stdin.readline().strip())

def getgrid():
    return map(lambda (l): map(int, sys.stdin.readline().strip().split()),
               range(4))

for t in range(getint()):
    n = getint() -1
    L = getgrid()
    n2 = getint() -1
    L2 = getgrid()

    candidates = set()
    for v in L[n]:
        if v in L2[n2]:
            candidates.add(v)
    
    prefix = 'Case #%d: ' % (t+1)
    l = len(candidates)
    if l == 0:
        print prefix + 'Volunteer cheated!'
    elif l > 1:
        print prefix + 'Bad magician!'
    else:
        v = [ v for v in candidates][0]
        print prefix + str(v)
