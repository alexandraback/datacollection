
def bits(n):
	n = (n & 0x5555555555555555) + ((n & 0xAAAAAAAAAAAAAAAA) >> 1)
	n = (n & 0x3333333333333333) + ((n & 0xCCCCCCCCCCCCCCCC) >> 2)
	n = (n & 0x0F0F0F0F0F0F0F0F) + ((n & 0xF0F0F0F0F0F0F0F0) >> 4)
	n = (n & 0x00FF00FF00FF00FF) + ((n & 0xFF00FF00FF00FF00) >> 8)
	n = (n & 0x0000FFFF0000FFFF) + ((n & 0xFFFF0000FFFF0000) >> 16)
	n = (n & 0x00000000FFFFFFFF) + ((n & 0xFFFFFFFF00000000) >> 32) # This last & isn't strictly necessary.
	return n

f = open('B-large.in', 'r')
out = open('B-large.out', 'w')

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def check(x, y, R, C):
	return x >= 0 and x < R and y >=0 and y < C

T = int(f.readline())
for t in xrange(1, T + 1):
	print t
	R, C, N = map(int, f.readline().split())
	SUM = R*C
	ans = None
	if N <= (SUM + 1) / 2:
		ans = 0
	else:
		N = SUM - N
		inner = (max(0, (R - 2)) * max(0, (C - 2)) + 1) / 2
		corner = None
		if SUM % 2 == 1:
			corner = 4
		else:
			corner = 2
		edge = SUM - inner - corner
		ans = (R-1)*C+R*(C-1)
		while N > 0:
			if inner > 0:
				ans -= 4
				inner -= 1
			elif edge > 0:
				ans -= 3
				edge -= 1
			else:
				ans -= 2
				corner -= 1
			N -=1



	out.write('Case #' + str(t) + ': ' + str(ans) + '\n')