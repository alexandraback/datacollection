def neighbors(R, C, N):
	from itertools import combinations

	best = float('inf')

	for combo in combinations(range(R * C), N):
		unhappiness = 0

		for apt in combo:
			if apt % C != 0 and apt - 1 in combo:
				unhappiness += 1
			if apt + C in combo:
				unhappiness += 1

		best = min(best, unhappiness)

	return best

def main():
	from sys import stdin
	input = stdin.read().split('\n')
	T = int(input[0])

	for t in range(T):
		R, C, N = map(int, input[t+1].split())

		print "Case #{0}: {1}".format(t + 1, neighbors(R, C, N))

if __name__ == '__main__':
	main()
