__author__ = 'PrimuS'
f = open("A-small-attempt0.in", "r")
of = open("A_res_small.txt", "w")

T = int(f.readline())

for t in range(1, T + 1):
    n = int(f.readline())
    m = [int(x) for x in f.readline().split()]
    res1 = 0
    res2 = 0
    rate = 0
    for i in range(n-1):
        res1 += max(0, m[i] - m[i+1])
        rate = max(rate, m[i] - m[i+1])
    for i in range(n-1):
        res2 += min(m[i], rate)

    print("Case #{:d}: {:d} {:d}".format(t, res1, res2), file=of)

of.close()
