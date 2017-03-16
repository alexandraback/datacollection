import sys

def solve1(ns):
	last, total = ns[0], 0
	for n in ns[1:]:
		if n < last:
			total += (last - n)
		last = n
	return total

def solve2(ns):
	ns1 = ns[:len(ns)-1]
	ns2 = ns[1:]
	nsd = [ns1[i] - ns2[i] for i in range(len(ns1))]
	rate = max(nsd)
	total = 0
	for i in range(len(nsd)):
		total += min(ns1[i], rate)
	return total

with open(sys.argv[1]) as f:
	t = int(f.readline())
	for i in range(t):
		n = f.readline()
		line = f.readline()

		ns = [int(x) for x in line.split()]
		result1 = solve1(ns)
		result2 = solve2(ns)
		print "Case #%d: %d %d" % (i+1, result1, result2)
