
r = open('3.test')
T = int(r.readline().rstrip())
for t in range(1, T+1):
    N = int(r.readline().rstrip())

    trees = []
    tree_min = [N-1 for i in range(N)]

    for tree in range(N):
        trees.append(map(int, r.readline().rstrip().split()))

    # Each line can be represented as ax + by + c
    lines = {}
    for i in range(N):
        for j in range(i+1, N):
            Xi, Yi = trees[i]
            Xj, Yj = trees[j]

            Ydiff = abs(Yj - Yi)
            Xdiff = abs(Xj - Xi)
    
            if Xdiff == 0:
                coords = (1, 0, -Xi)
            elif Ydiff == 0:
                coords = (0, 1, -Yi)
            else:
                coords = (Yj-Yi, Xi-Xj,Xj*Yi-Xi*Yj)

            if coords not in lines:
                if Xdiff == 0:
                    lowest = i if Yi < Yj else j
                else:
                    lowest = i if Xi < Xj else j

                highest = i if lowest == j else j
                lcut = 0
                rcut = 0
                a, b, c = coords

                vlist = []
                for k in range(N):
                    Xk, Yk = trees[k]
                    val = a*Xk + b*Yk + c
                    if val < 0:
                        lcut += 1
                    elif val > 0:
                        rcut += 1
                    else:
                        vlist.append(k)

                lines[coords] = [lowest, highest, lcut, rcut, vlist]

            else:
                lowest, highest, lcut, rcut, vlist = lines[coords]
                Xlowest, Ylowest = trees[lowest]
                Xhighest, Yhighest = trees[highest]

                if Xdiff == 0:
                    if Yi < Ylowest:
                        lines[coords][0] = i
                    if Yj < Yi:
                        lines[coords][0] = j

                    if Yi > Yhighest:
                        lines[coords][1] = i
                    if Yj > Yi:
                        lines[coords][1] = j

                else:
                    if Xi < Xlowest:
                        lines[coords][0] = i
                    if Xj < Xi:
                        lines[coords][0] = j

                    if Xi > Xhighest:
                        lines[coords][1] = i
                    if Xj > Xi:
                        lines[coords][1] = j


    # Now lines should contain the latest info about endpoints
    for coords in lines:
        lowest, highest, lcut, rcut, vlist = lines[coords]
        for v in vlist:
            if v == lowest or v == highest:
                if min(lcut, rcut) == 0:
                    tree_min[v] = 0
            else:
                tree_min[v] = min(lcut, rcut, tree_min[v])

    print 'Case #%d:' % t
    for tree in tree_min:
        print tree
r.close()
