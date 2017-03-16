for T in range(1, input() + 1):
    xn = input()
    xs = map(int, raw_input().split())

    y = 0
    pz = 0
    for i in range(len(xs) - 1):
        yy = xs[i] - xs[i + 1]
        if yy > 0:
            y += yy
        if yy > pz:
            pz = yy

    z = 0
    if pz > 0:
        for i in range(len(xs) - 1):
            if xs[i] <= pz:
                z += xs[i]
            else:
                z += pz

    print "Case #%d: %d %d" % (T, y, z)
