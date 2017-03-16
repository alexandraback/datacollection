import sys
input = file(sys.argv[1])

def solve1(s):
    ans = 0
    l = len(s)
    for i in range(l-1):
        ans += max(0, s[i] - s[i+1])
    return ans

def solve2(s):
    m = 0
    ans = 0
    l = len(s)
    for i in range(l-1):
        m = max(m, s[i] - s[i+1])
    for i in range(l-1):
        ans += min(m, s[i])
    return ans

for case in range(int(input.readline())):
    input.readline()
    vals = [int(x) for x in input.readline().split()]
    print "Case #%d: %d %d" % (case+1, solve1(vals), solve2(vals))
