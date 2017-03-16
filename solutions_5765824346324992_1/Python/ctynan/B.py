def haircuts(time, m):
    num = 0
    for i, v in enumerate(m):
        num += 1 + int(time / m[i])
    return num

def getAvailable(time, m):
    avail = []
    for i, v in enumerate(m):
        if time % m[i] == 0:
            avail.append(i+1)
    return avail

def main():
    f_in = open('/Users/ctynan/Downloads/B-large.in', 'r')
    f_out = open('/Users/ctynan/Downloads/B-large.out', 'w')

    T = int(f_in.readline())

    for tst in range(T):
        ln = f_in.readline().strip('\n').split(' ')
        B, N = int(ln[0]), int(ln[1])
        m = f_in.readline().strip('\n').split(' ')
        m = map(lambda x: int(x), m)

        if N <= B:
            f_out.write(("Case #%i: %i\n") % (tst+1, N))
            continue

        lo, hi = 0, 1000000000000

        while(hi - lo > 1):
            cur = lo + ((hi - lo) / 2)

            num = haircuts(cur, m)
            if num < N:
                lo = cur
            else:
                hi = cur

        avail = getAvailable(hi, m)
        queueSpot = N - haircuts(lo, m)
        bestBarber = avail[queueSpot - 1]


        f_out.write(("Case #%i: %i\n") % (tst+1, bestBarber))

    return

def __init__():
    pass

main()


