
def bits(n):
	n = (n & 0x5555555555555555) + ((n & 0xAAAAAAAAAAAAAAAA) >> 1)
	n = (n & 0x3333333333333333) + ((n & 0xCCCCCCCCCCCCCCCC) >> 2)
	n = (n & 0x0F0F0F0F0F0F0F0F) + ((n & 0xF0F0F0F0F0F0F0F0) >> 4)
	n = (n & 0x00FF00FF00FF00FF) + ((n & 0xFF00FF00FF00FF00) >> 8)
	n = (n & 0x0000FFFF0000FFFF) + ((n & 0xFFFF0000FFFF0000) >> 16)
	n = (n & 0x00000000FFFFFFFF) + ((n & 0xFFFFFFFF00000000) >> 32) # This last & isn't strictly necessary.
	return n

f = open('B-small.in', 'r')
out = open('B-small.out', 'w')

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def check(x, y, R, C):
	return x >= 0 and x < R and y >=0 and y < C

T = int(f.readline())
for t in xrange(1, T + 1):
	print t
	R, C, N = map(int, f.readline().split())
	lim = 2**(R*C)
	ans = 99999999
	for i in xrange(lim):
		if bits(i) != N:
			continue
		#print 'QQ', i, bits(i)
		#print i
		grid = [([0] * C) for r in xrange(R)]
		#print i
		for b in xrange(R*C):
			#print b, i
			if ((1<<b) & i) != 0:
				#print b,
				grid[b / C][b % C] = 1
		#print grid
		tmp = 0
		for r in xrange(R):
			for c in xrange(C):
				for d in xrange(4):
					tx, ty = r + dx[d], c + dy[d]
					if check(tx, ty, R, C) and grid[r][c] * grid[tx][ty] != 0:
						tmp += 1
		#print ans, tmp
    #print tmp
		ans = min(ans, tmp)
	out.write('Case #' + str(t) + ': ' + str(ans / 2) + '\n')