number_cases = int(raw_input())

def m1(vals):
	min_count = 0
	for a, b in zip(vals, vals[1:]):
		if b < a:
			min_count += a - b
	return min_count

def m2(vals):
	min_count = 0
	for a, b in zip(vals, vals[1:]):
		if b < a and min_count < a - b:
			min_count = a - b
	initial_guess = min_count * (len(vals) - 1)
	for el in vals[:-1]:
		if el < min_count:
			initial_guess -= min_count - el
	return initial_guess

for i in xrange(number_cases):
	ss = int(raw_input())
	vals = [int(x) for x in raw_input().split()]
	print "Case #{}: {} {}".format(i+1, m1(vals), m2(vals))