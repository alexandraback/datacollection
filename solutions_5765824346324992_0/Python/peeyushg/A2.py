def gcd(a, b):
	if b==0:
		return a
	else:
		return gcd(b, a%b)

T =  int(raw_input())
for t in range(T):
	B, N = [int(i) for i in raw_input().split()]
	vals = [int(i) for i in raw_input().split()]
	mul = 1
	g = vals[0]
	for i in range(B):
		mul*=vals[i]
		g = gcd(g, vals[i])
	mul /= g
	count = 0
	for i in range(B):
		count += mul/vals[i] 
	N = N%count
	if N == 0:
		N = count
	temp = [0]*B	
	for i in range(N):
		min_ = 100000000
		for j in range(B):
			if temp[j] < min_:
				min_ = temp[j]
				index = j
		temp[index] += vals[index]
		if i == N-1:
			ans = index+1

	print "Case #"+str(t+1)+":", ans
