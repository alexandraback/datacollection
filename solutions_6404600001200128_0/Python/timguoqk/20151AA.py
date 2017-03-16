# https://code.google.com/codejam/contest/4224486/dashboard

if __name__ == "__main__":
    filein = open('20151AA.in', 'r')
    fileout = open('20151AA.out', 'w')
    T = int(filein.readline())
    for t in range(T):
        fileout.write('Case #%d: ' % (t + 1))
        N = int(filein.readline())
        m = list(map(int, filein.readline().split()))
        ans = [0, 0]
        rate = 0
        for i in range(N - 1):
            if m[i] > m[i + 1]:
                diff = m[i] - m[i + 1]
                ans[0] += diff
                rate = max(rate, diff)

        for i in range(N - 1):
            if m[i] <= rate:
                ans[1] += m[i]
            else:
                ans[1] += rate

        fileout.write('%d %d\n' % (ans[0], ans[1]))

    filein.close()
    fileout.close()
