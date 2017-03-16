t = int(input())
for i in range(1, t + 1):
    a = [[]] * 4
    ps = {i for i in range(1, 17)}
    fans = int(input())
    for j in range(4):
        a[j] = list(map(int, input().split()))
    pps = set(a[fans - 1])
    ps.intersection_update(pps)
    fans = int(input())
    for j in range(4):
        a[j] = list(map(int, input().split()))
    pps = set(a[fans - 1])
    ps.intersection_update(pps)
    if len(ps) == 0: print("Case #%d: Volunteer cheated!" % (i,))
    elif len(ps) > 1: print("Case #%d: Bad magician!" % (i,))
    else:
        for j in range(1, 17):
            if j in ps:
                print("Case #%d: %d" % (i, j))
