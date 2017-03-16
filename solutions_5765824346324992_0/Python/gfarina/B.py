import sys

lines = sys.stdin.readlines()

def ceil(a, b):
	return (a + b - 1) / b

def testcase(t):
	B, N = map(int, lines[2 * t - 1].split())
	Ms = map(int, lines[2 * t].split())

	lb = 0
	ub = 100000 * 1000000000 * 2

	best = lb
	while lb <= ub:
		time = (lb + ub) / 2
		
		served = 0
		for M in Ms:
			served += ceil(time, M)

		if served >= N: # gia' troppi
			ub = time - 1
		else:
			best = time
			lb = time + 1

	# print best
	free_barbers = []
	for i in xrange(B):
		if best % Ms[i] == 0:
			free_barbers += [i]

	served = 0
	for M in Ms:
		served += ceil(best, M)

	# print served, free_barbers

	ans = free_barbers[N - served - 1] + 1

	print "Case #%d: %d" % (t, ans)

T = int(lines[0])
for t in xrange(1, T + 1):
	testcase(t)