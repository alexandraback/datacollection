def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

T = readint()
for t in range(T):

    N = readint()

    m_i = readarray(int)
    # method 1
    res = 0
    prev = m_i[0]
    for cur in m_i[1:]:
        if prev > cur:
            res += (prev-cur)
        prev = cur

    # method 2
    l_diff = list()
    prev = m_i[0]
    for x in m_i[1:]:
        l_diff.append(prev-x)
        prev = x
    maxe = max(l_diff)
    res2 = 0
    prev = m_i[0]
    for cur in m_i[1:]:
        if prev-maxe < 0:
            res2 += prev
        else:
            res2 += maxe
        prev = cur
    print 'Case #%i: %d %d'%((t+1), res, res2)
