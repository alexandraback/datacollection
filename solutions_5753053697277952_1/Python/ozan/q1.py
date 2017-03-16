def argMax(p):
    i = -1
    M = -1
    for j, x in enumerate(p):
        if M < x:
            M = x
            i = j
    return i

def getChar(c):
    return chr(ord('A') + c)

def evacuate(Ps, total):
    j0 = argMax(Ps)
    Ps[j0] -= 1
    if total>1:
        j1 = argMax(Ps)
        Ps[j1] -= 1
        M = max(Ps)
        if M * 2 > total - 2:
            Ps[j1] += 1
            return chr(ord('A') + j0)
        return chr(ord('A') + j0)+ chr(ord('A') + j1)
    return getChar(j0)

def solve():
    N = int(raw_input())
    Ps = map(int, raw_input().split(' '))
    plan = []
    total = sum(Ps)
    while total:
        p = evacuate(Ps, total)
        total -= len(p)
        plan.append(p)
    return ' '.join(plan)
                    
def main():
    T = int(raw_input())
    for i in xrange(T):
        print 'Case', '#%d:' % (i+1,), solve()

if __name__ == '__main__':
    main()
