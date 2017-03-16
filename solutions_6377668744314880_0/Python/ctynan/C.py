def orient(a, b, c):
    ax, ay = a
    bx, by = b
    cx, cy = c

    ret = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax)

    if ret == 0:
        return 0
    if ret > 0:
        return -1
    if ret < 0:
        return 1

    pass

def main():
    f_in = open('/Users/ctynan/Downloads/C-small-attempt0.in', 'r')
    f_out = open('/Users/ctynan/Downloads/C-small-attempt0.out', 'w')

    T = int(f_in.readline())

    for tst in range(T):
        N = int(f_in.readline().strip('\n'))
        points = []
        for i in range(N):
            lv = f_in.readline().strip('\n').split(' ')
            points.append((int(lv[0]), int(lv[1])))

        res = []

        for i in range(N):
            curPoint = points[i]
            minCost = 20

            for j in range(N):
                if i == j:
                    continue
                prevPoint = points[j]

                cost = 0

                for k, otherPoint in enumerate(points):
                    if j == k:
                        continue


                    if orient(prevPoint, curPoint, otherPoint) > 0:
                        cost += 1

                minCost = min(cost, minCost)

            res.append(minCost)
        
        f_out.write(("Case #%i:\n") % (tst+1))

        for i, v in enumerate(res):
            f_out.write(("%i\n") % (v))

    return

def __init__():
    pass

main()


