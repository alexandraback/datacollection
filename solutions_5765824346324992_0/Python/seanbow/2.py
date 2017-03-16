
from fractions import gcd

#def gcd(*numbers):
#    """Return the greatest common divisor of the given integers"""
#    return reduce(gcd, numbers)
 
# Least common multiple is not in standard libraries? It's in gmpy, but this is simple enough:
 
def lcm(numbers):
	"""Return lowest common multiple of a list."""    
	def lcm(a, b):
		return (a * b) // gcd(a, b)
	return reduce(lcm, numbers, 1)
    
f = open("2.in");
lines = [l.strip() for l in f]

ncases = int(lines[0])

#outfile = open("2.out", "w")
output_str = 'Case #{0}: {1}'

for i in range(1, ncases+1):
	BN = lines[2*i - 1].split()
	B = int(BN[0])
	N = int(BN[1])

	inp = [int(x) for x in lines[2*i].split()]
	M = inp

	period = lcm(inp)
	P=period
	# number of cuts in a period P
	# = P/M1 + P/M2 + ... + P/MB
	cuts = [P/m for m in M]
	ncuts = sum(cuts)

	N = (N - 1)%ncuts + 1

	# work through times
	done = 0
	cuts_so_far = 0
	for t in range(period):
#		print('t = ' + str(t))
		for j in range(B):
#				print('barber ' + str(j))
			if t == 0 or t % M[j] == 0:
#				print('t = ' + str(t) + ' gets a cut by barber ' + str(j))
				cuts_so_far += 1
				if cuts_so_far == N:
					print(output_str.format(i, j+1))
					done = 1
		
			if done:
				break
		if done: 
			break

	#	if not done:
	#		print('shit')
	#		print(output_str.format(i, B))
					  
			    
			    
			    
