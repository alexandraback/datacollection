fo = open("sm.in", "r")

T = int(fo.readline())


for zzz in range(T):
    n = int(fo.readline())
    p = [int(l) for l in fo.readline().split()]
    t = sum(p)
    al = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

    m = [[p[i], al[i]] for i in range(n)]

    m.sort()

    ans = []

    while(True):
        if(t == 2):
            m.sort()
            f = m[-1][1]
            m[-1][0] -= 1
            m.sort()
            s = m[-1][1]
            m[-1][0] -= 1
            ans.append(f+s)
            break

        if(t == 3):
            m.sort()
            f = m[-1][1]
            m[-1][0] -= 1
            ans.append(f)
            t -= 1
            continue

        m.sort()
        f = m[-1][1]
        m[-1][0] -= 1
        m.sort()
        s = m[-1][1]
        m[-1][0] -= 1
        t -= 2
        ans.append(f+s)

    print 'Case #%d: %s' % (zzz+1, " ".join(ans))

