
t = int(input())

for case in range(1, t + 1):
    n = int(input())
    m = 0
    sizes = list(map(int, input().split()))
    m = sum(sizes)
    sizes = [[s, i] for i, s in enumerate(sizes)]
    plan = []
    evac = 0
    def ok():
        for s, i in sizes:
            if s > (m - evac) / 2:
                return False
        return True

    while evac < m:
        s, i = max(sizes)
        evac += 1
        sizes[i][0] -= 1
        if ok():
            plan.append([i])

            continue
        s, j = max(sizes)
        evac += 1
        sizes[j][0] -= 1
        if ok():
            plan.append([i, j])
        else:
            print("jklsdafgljksdk")

    splan = []
    for p in plan:
        splan.append("")
        for i in p:
            splan[-1] += chr(i + ord("A"))

    splan = " ".join(splan)
    print("Case #{}: {}".format(case, splan))
