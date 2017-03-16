#!/usr/bin/python2.7

def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""   
    return reduce(lcm, args)

for case in range(input()):
	B, N = map(int, raw_input().split())
	data = map(int, raw_input().split())

	sol = 1
	if (B > 1):
		new_data = list(set(data))
		minimo = new_data[0]
		if (len(new_data) > 1):
			for i in xrange(1, len(new_data)):
				minimo = lcm(minimo, new_data[i])

#	print minimo

	cuantos = []
	for d in data:
		cuantos.append(minimo/d)

#	print cuantos
	if (N > sum(cuantos)):
		N = N % sum(cuantos)

	if (N == 0):
		N = sum(cuantos)
#	print N

	sol = N
	t = 0
	while (N > 0):
#		print ' * t', t
		for i in xrange(B):
			if (t % data[i]) == 0:
				N -= 1
				if (N == 0):
					sol = i + 1
		t += 1
#	print sol

	print 'Case #%s: %s' % ((case + 1), sol)

