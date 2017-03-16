T = int(input())
for I in range(1, T+1):
    n = int(input())
    parties = [int(x) for x in input().split()]

    def l(i):
        return chr(ord('A') + i)

    od = [(parties[i], l(i)) for i in range(0, len(parties))]
    od.sort()
    od.reverse()

    plan = []
    for count, let in od:
        for j in range(0, count):
            plan.append((count-j, let))

    plan.sort()
    res = []
    for i in range(0, len(plan)//2):
        res.append(plan[2*i][1] + plan[2*i+1][1])
    if len(plan) % 2 == 1:
        res.append(plan[-1][1])
    res.reverse()
    result = ' '.join(res)
    print("Case #%d: %s" % (I, str(result)))
