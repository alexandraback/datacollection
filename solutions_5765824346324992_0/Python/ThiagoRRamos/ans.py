import heapq

number_cases = int(raw_input())

def mdc(a, b):
	if a % b == 0:
		return b
	return mdc(b, a % b)

def mmc(*vals):
	if len(vals) > 2:
		return mmc(mmc(vals[0], vals[1]), *vals[2:])
	return vals[0] * vals[1] / mdc(vals[0], vals[1])

def solve(vals, n):
	if n < len(vals):
		return n
	m = mmc(*vals)
	cycle = sum(m/x for x in vals)
	if n > cycle:
		n = n % cycle
		if n == 0:
			n = cycle
	h = []
	for number_barber, el in enumerate(vals):
		heapq.heappush(h, (0, number_barber + 1, el))
	count = 1
	while count < n:
		count += 1
		current_time, number_barber, cost = heapq.heappop(h)
		heapq.heappush(h, (current_time + cost, number_barber, cost))
	return h[0][1]

for i in xrange(number_cases):
	b, n = [int(x) for x in raw_input().split()]
	vals = [int(x) for x in raw_input().split()]
	assert len(vals) == b
	print "Case #{}: {}".format(i+1, solve(vals, n))