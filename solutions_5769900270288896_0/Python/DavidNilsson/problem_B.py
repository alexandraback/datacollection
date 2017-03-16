import sys
import itertools

cases = int(raw_input())


def solve(R, C, N):
	best = 1000000
	for comb in itertools.combinations(range(R*C), N):
		board = [[0 for k in range(R)] for sadasd in range(C)]
		for k in comb:
			board[k % C][k / C] = 1
		score = 0
		for i in range(C):
			for j in range(R):
				if board[i][j] == 1:
					if i+1 < C and board[i+1][j] == 1:
						score += 1
					if j+1 < R and board[i][j+1] == 1:
						score += 1
		best = min(score, best)
	return best

for current_case in range(1, cases+1):
	R,C,N = raw_input().split()
	R,C,N = int(R), int(C), int(N)
	
	ans = solve(R, C, N)
	
	print "Case #%d: %d" % (current_case, ans)