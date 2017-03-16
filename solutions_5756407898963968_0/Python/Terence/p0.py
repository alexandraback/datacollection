def score(v1, v2):
    j = len(v2)-1
    sc = 0
    for i in range(len(v1)-1, -1, -1):
        while j >= 0 and v2[j] >= v1[i]:
            j -= 1
        if j < 0:
            break
        sc += 1
        j -= 1
    return sc

t = int(raw_input())
for iCase in range(1, t+1):
    r1 = int(raw_input())
    b1 = list()
    for _ in range(4):
        b1.append(map(int, raw_input().split()))
    r2 = int(raw_input())
    b2 = list()
    for _ in range(4):
        b2.append(map(int, raw_input().split()))
    d = set(b1[r1-1]) & set(b2[r2-1])
    if len(d) <= 0:
        print 'Case #%d: Volunteer cheated!' % iCase
    elif len(d) > 1:
        print 'Case #%d: Bad magician!' % iCase
    else:
        print 'Case #%d: %d' % (iCase, d.pop())
