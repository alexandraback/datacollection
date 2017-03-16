T = int(raw_input())
for t in xrange(T):
    N = int(raw_input())
    p = map(int, raw_input().split())
    data = []
    count = 0
    for i, k in enumerate(p):
        count += k
        data.append([k, chr(i + ord("A"))])

    print "Case #" + str(t + 1) + ":",
    while count > 0:
        data.sort(reverse=True)
        if count == 3:
            print data[0][1],
            data[0][0] -= 1
            count -= 1
        elif count == 1:
            print data[0][1],
            data[0][0] -= 1
            count -= 1
        else:
            print data[0][1] + data[1][1],
            data[0][0] -= 1
            data[1][0] -= 1
            count -= 2

    print ""
