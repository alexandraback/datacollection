# Google Code Jam 2015, Round 1A
# Problem B. Haircut
# Lance C. Simons

# http://en.wikipedia.org/wiki/Euclidean_algorithm
def gcd(a,b):
	while b > 0:
		t = b
		b = a % b
		a = t
	return a

# http://en.wikipedia.org/wiki/Least_common_multiple
def lcm(a,b):
	return (a / gcd(a,b)) * b

def lcmv(vals):
	return reduce(lcm, vals)

def barber_ID(B, N, barber_times):

	if N < B:
		return N

	# Barbers will repeat on a cycle - find the cycle length, and shift ahead to the correct position
	cycle_len = lcmv(barber_times)
	cycle_customers = sum([cycle_len / bt for bt in barber_times])

	N = N % cycle_customers

	if N < B:
		return N

	N -= len(barber_times)

	barber_queues = barber_times[:]

	while True:
		delay = min(barber_queues)

		for i in range(len(barber_queues)):
			barber_queues[i] -= delay
			if barber_queues[i] == 0:
				if N == 0:
					return i
				else:
					N -= 1
				barber_queues[i] = barber_times[i]


def go(infilename, outfilename):
	inf = open(infilename, "r")
	outf = open(outfilename, "w")
	runs = int(inf.next().strip())
	for i in range(runs):
		B, N = map(int, inf.next().strip().split())
		barber_times = map(int, inf.next().strip().split())
		outf.write("Case #%d: %d\n" % (i+1, barber_ID(B, N-1, barber_times)+1 ) )


if __name__ == "__main__":
	import sys
	go(sys.argv[1], sys.argv[1].replace(".in", ".out"))