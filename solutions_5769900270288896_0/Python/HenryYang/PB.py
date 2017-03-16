import sys
input = file(sys.argv[1])

def calc(r, c, s):
    a = [[0 for x in range(c)] for x in range(r)]
    for i in range(r*c):
        a[i/c][i%c] = s%2
        s /= 2
    ct = 0
    for i in range(r):
        for j in range(c-1):
            if a[i][j] and a[i][j+1]:
                ct += 1
    for i in range(r-1):
        for j in range(c):
            if a[i][j] and a[i+1][j]:
                ct += 1
    return ct
def solve1(r, c, n):
    ans = 1000000000
    for i in range(1<<(r*c)):
        s = bin(i).replace('0b', '')
        if s.count('1') == n:
            ans = min(ans, calc(r, c, i))

    return ans

for case in range(int(input.readline())):
    vals = [int(x) for x in input.readline().split()]
    print "Case #%d: %d" % (case+1, solve1(vals[0], vals[1], vals[2]))
