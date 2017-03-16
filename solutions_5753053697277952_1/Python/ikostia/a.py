def read_input():
    n = int(raw_input())
    p = map(int, raw_input().split())
    return n, p

def print_output(i, output):
    print "Case #%i: %s" % (i+1, output)

def solve(i, input):
    n, p = input
    p = [(v, chr(ord('A') + i)) for i, v in enumerate(p)]
    p.sort()
    res = []
    delta_max = p[-1][0] - p[-2][0]
    res += [p[-1][1]] * delta_max
    p[-1] = (p[-2][0], p[-1][1])
    for i in xrange(n-2):
	res += [p[i][1]] * p[i][0]
    res += [ p[-1][1] + p[-2][1] ] * p[-2][0]	
    return ' '.join(res)

if __name__ == "__main__":
    t = int(raw_input())
    for i in xrange(t):
        input = read_input()
        output = solve(i, input)
        print_output(i, output)

