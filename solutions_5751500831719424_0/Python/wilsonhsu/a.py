
def read_input(filename):
	f = open(filename)
	T = int(f.readline())
	test_cases = [None] * T
	for t in range(T):
		N = int(f.readline())
		test_cases[t] = [None] * N
		for n in range(N):
			test_cases[t][n] = f.readline().strip()

	f.close()

	return test_cases

def count_char(canonical, test_string):
	count = [0] * len(canonical)

	k = 0
	for i in range(len(canonical)):
		while k < len(test_string) and test_string[k] == canonical[i]:
			count[i] += 1
			k += 1
		if count[i] == 0:
			return None

	if k < len(test_string):
		return None
	else:
		return count
		
def find_canonical(test_case):
	N = len(test_case)
	
	canonical = [test_case[0][0]]

	for i in range(1, len(test_case[0])):
		if test_case[0][i] != test_case[0][i-1]:
			canonical.append(test_case[0][i])

	return canonical

def compute_min_moves(count):
	count = sorted(count)

	K = len(count)

	diff1 = sum([abs(u-count[K/2]) for u in count])

	if K%2==1 or count[K/2]==count[K/2-1]:
		return diff1

	diff2 = sum([abs(u-count[K/2-1]) for u in count])
	return min(diff1, diff2)

def solve(test_case):
	canonical = find_canonical(test_case)
	counts = [None] * len(canonical)
	for k in range(len(counts)):
		counts[k] = [None] * len(test_case)

	for i in range(len(test_case)):
		count = count_char(canonical, test_case[i])
		if count == None:
			return 'Fegla Won'
		else:
			for k in range(len(canonical)):
				counts[k][i] = count[k]

	min_moves = 0
	for k in range(len(counts)):
		min_moves += compute_min_moves(counts[k])

	return min_moves

def solve_all(testid):
	inputfile = testid + '.in'
	outputfile = testid + '.out'

	test_cases = read_input(inputfile)

	g = open(outputfile, 'w')

	t = 1
	for test_case in test_cases:
		result = solve(test_case)
		g.write('Case #{}: {}\n'.format(t, result))
		t += 1

	g.close()

if __name__ == '__main__':
#	solve_all('sample')
#	solve_all('test')
	solve_all('A-small-attempt0')
