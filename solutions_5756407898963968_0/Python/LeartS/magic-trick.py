
messages = ('Volunteer cheated!',
            '{}',
            'Bad magician!',)

solutions = []
with open('magic-trick.in', 'r') as f:
	test_cases = int(f.readline())

	for t in xrange(test_cases):
		answers = []
		answers.append(int(f.readline()))
		matrix_start = [[int(s) for s in f.readline().strip().split()] for i in xrange(4)]
		candidates = set(matrix_start[answers[0]-1])
		answers.append(int(f.readline()))
		matrix_end = [[int(s) for s in f.readline().strip().split()] for i in xrange(4)]
		sol = candidates & set(matrix_end[answers[1]-1])
		
		solutions.append(
			'Case #{}: {}\n'.format(t+1, messages[min(2, len(sol))].format(sol and sol.pop()))
		)

with open('magic-trick.out', 'r+') as f:
	f.writelines(solutions)
	f.seek(0)
	print f.read()
		
