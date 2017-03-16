g = open("data1.txt", 'w')
with open("data.txt", 'r') as f:
    T = int(f.readline())
    for r in range(T):
        N = int(f.readline())
        m = [int(x) for x in f.readline().split()]
        first_sum = 0
        for i in range(1, N):
            if m[i] < m[i-1]:
                first_sum += (m[i-1] - m[i])

        biggest_gap = 0
        for i in range(1, N):
            if m[i] < m[i-1]:
                biggest_gap = max(biggest_gap, (m[i-1] - m[i]))

        #while biggest_gap%10 != 0:
        #    biggest_gap += 1
        #min_rate = biggest_gap/10

        sec_sum = 0
        for i in range(N-1):
            sec_sum += min(m[i], biggest_gap)

        g.write("Case #%d: %d %d\n" % (r+1, first_sum, sec_sum))
f.close()
g.close()