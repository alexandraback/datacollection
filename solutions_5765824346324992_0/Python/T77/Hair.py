file1 = open("B-small-attempt2.in", "r")
my_file = open("output.txt", "r+")

def loopy(N, B, inputs = []):
	new_list = list(inputs)
	N = N-B
	while ( N != 0):	
		for x in range(B):
				
			new_list[x] = new_list[x]-1
			if new_list[x] == 0:
				N = N-1
				if N == 0:
					a = x+1
					return a
				new_list[x] = inputs[x]        
	
t = int(file1.readline())
i = 0
while (i < t):
	a = 0
	z1 = (file1.readline().split())
	z = [int(j) for j in z1]
	inputs1 = (file1.readline().split())
	inputs = [int(k) for k in inputs1]

	def red(f, g):
		while g:      
			f, g = g, f % g
		return f

	def lcm(f, g):
	    return f * g // red(f, g)

	def lcmdelta(*args):
	    return reduce(lcm, args)
	BigLcm = (lcmdelta(*inputs))
	B = z[0]
	num = 0
	for x in range(B):
	       num += BigLcm /inputs[x]
	
	if z[0] >= z[1]:
		a = z[1]
	else:
		N = z[1]
		N = N%num
		if N ==0:
			N = num
	if a == 0:
		if N <= B:
		    a = N    
	if a == 0:
		a = loopy(N, B, inputs)	
	i+=1		
	my_file.write(("Case #%d: %d\n" % (i,a)))
my_file.close()
file1.close()
