import sys
input = file(sys.argv[1])
#input = file('sample.in')
def solve1(r, c, n):
    ans = r*(c+1) + c * (r+1)
    ans -= n*4
    return max(0, -ans)

for case in range(int(input.readline())):
    vals = [int(x) for x in input.readline().split()]
    print "Case #%d: %d" % (case+1, solve1(vals[0], vals[1], vals[2]))
