def solve(R, C, N):
	X = R / 2 * ( (C+1)/2 + C/2 )
	if R % 2 == 1:
		X += (C+1)/2
	
	N -= X
	ret = 0
	if N <= 0:
		return 0
	else:
		if R % 2 == 1 and C % 2 == 1:		#both odd
			v = 2 * ( R/2 + C/2 )
			if N <= v:
				if R == 3 and N > (C+1)/2 and N < R * C - X:
					return N * 3 - 1
				elif C == 3 and N > (R+1)/2 and N < R * C - X:
					return N * 3 - 1
				return N * 3
			N -= v
			return v * 3 + N * 4
		elif R % 2 == 0 and C % 2 == 0:		#both even
			if N <= 2:
				return N * 2
			N -= 2
			v = 2 * (R/2 -1) + 2 * (C/2 - 1)
			if N <= v:
				return N * 3 + 2 * 2
			
			N -= v
			return v * 3 + 2 * 2 + N * 4
		else:
			if N <= 2:
				return N * 2
			N -= 2
			if R % 2 == 0:
				C, R = R, C
			v = 2 * (C/2 - 1) + R/2
			if N <= v:
				return N * 3 + 2 * 2
			N -= v
			return v * 3 + 2 * 2 + N * 4
	
T = input()

arr = []
for i in range(16):
	arr.append(0)
			
for tc in range(T):

	R, C, N = map(int, raw_input().split())
	print "Case #%d: %d" % (tc+1, solve(R,C,N))

	
	
	
