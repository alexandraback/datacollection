grid = []
r, c = 0, 0
maxh = 1000000

def backtrack(nr, nc, ntenant, nh):
	global grid, r, c, maxh
	
	if ntenant <= 0:
		maxh = min(maxh, nh)
		
		return None
	
	if nr == r:
		return None
	
	for b in [True, False]:
		grid[nr][nc] = b
	
		# Check neighbors
		nhctr = 0
		if b:
			if nr > 0 and grid[nr - 1][nc]:
				nhctr += 1
			
			if nc > 0 and grid[nr][nc - 1]:
				nhctr += 1
			
			if nr + 1 < r and grid[nr + 1][nc]:
				nhctr += 1
			
			if nc + 1 < c and grid[nr][nc + 1]:
				nhctr += 1
		
		# Go deep
		if nc + 1 < c:
			backtrack(nr, nc + 1, ntenant - (0 if b is False else True), nh + nhctr)
		else:
			backtrack(nr + 1, 0, ntenant - (0 if b is False else True), nh + nhctr)

def main():
	global grid, r, c, maxh
	
	testcases = int(raw_input())
	
	for t in range(1, testcases + 1):
		r, c, nt = map(int, raw_input().split())
		
		grid = [[False for i in range(c)] for i in range(r)]
		maxh = 1000000
		backtrack(0, 0, nt, 0)
		
		print "Case #" + str(t) + ":", maxh

if __name__ == "__main__":
	main()