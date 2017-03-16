import sys

def solve1(N, m):
    num = 0
    for i in range(1, N):
        if m[i] < m[i-1]:
            num += m[i-1] - m[i]
    return num

def solve2(N, m):
    e = 0
    for i in range(1, N):
        if m[i] < m[i-1]:
            e = max(e, m[i-1] - m[i])
    if e == 0:
        return 0
    r = e / float(10)
    num = 0
    max_e = int(10 * r)
    for i in range(N-1):
        if m[i] >= max_e:
            num += max_e
        else:
            num += m[i]
    return num

#------------------------------------------------
# main process
if __name__ == "__main__":
    path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
    in_file = open(path, 'r')

    T = int(in_file.readline())
    for case_num in range(T):
        N = int(in_file.readline())
        m = [int(z) for z in in_file.readline().split()]
        n1 = solve1(N, m)
        n2 = solve2(N, m)
        print "Case #{}: {} {}".format(case_num+1, n1, n2)

    in_file.close()
