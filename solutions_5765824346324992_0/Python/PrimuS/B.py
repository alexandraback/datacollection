__author__ = 'PrimuS'
f = open("B-small-attempt0.in", "r")
of = open("B_small_res.txt", "w")

T = int(f.readline())

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

for t in range(1, T + 1):
    b, n = [int(x) for x in f.readline().split()]
    m = [int(x) for x in f.readline().split()]

    res = 0

    if b == 1:
        res = 1
    else:
        nsk = m[0] * m[1] // gcd(m[0], m[1])
        for i in range(2, b):
            # if nsk > n:
            #     break
            nsk = nsk * m[i] // gcd(nsk, m[i])
        if True: #n > nsk:
            k = 0
            for x in m:
                # if k > n:
                #     break
                k += nsk // x
            n %= k
            if n == 0:
                n = k

        up = nsk
        avail = [0] * up
        for x in m:
            cur = 0
            while cur < up:
                avail[cur] += 1
                cur += x

        for i in range(up):
            if n <= avail[i]:
                for j in range(b):
                    if i % m[j] == 0:
                        n -= 1
                    if n == 0:
                        res = j + 1
                        break
                break
            n -= avail[i]
    print("Case #{:d}: {:d}".format(t, res), file=of)

of.close()
