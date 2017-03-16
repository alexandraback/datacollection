f = open('A-large.in')
fw = open('A-large.out', 'w')

cases = int(f.readline())
for case in range(cases):
	N = int(f.readline())
	M = map(int, f.readline().split())
	eat_1 = 0
	eat_2 = 0
	max_eat = 0
	current = 0
	for m in M:
		if m < current:
			eat_1 += current - m
			if current - m > max_eat:
				max_eat = current - m
		current = m

	for m in M[:N-1]:
		if m > max_eat:
			eat_2 += max_eat
		else:
			eat_2 += m

	fw.write('Case #' + str(case + 1) + ': ' + str(eat_1) + ' ' + str(eat_2) + '\n')

fw.close()
f.close()
