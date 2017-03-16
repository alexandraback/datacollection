fin = open('B-small-attempt1.in', 'r')
fout = open('B.out', 'w')

cases = int(fin.readline().rstrip('\n'))

def stay(line, position, c):
	ref = (float('inf'), [])
	for element in line:
		unhappiness, occupied = element
		if position in occupied:
			continue
		actual = 0
		for neighbor in occupied:
			if position/c == neighbor/c and (position%c == neighbor%c - 1 or position%c == neighbor%c + 1):
				actual += 1
			elif position%c == neighbor%c and (position/c == neighbor/c - 1 or position/c == neighbor/c + 1):
				actual += 1
		if actual + unhappiness < ref[0]:
			ref = (unhappiness+actual, occupied + [position])
	return ref

for case in xrange(1, cases+1):
	answer = 'Case #' + str(case) + ': '
	# print case
	r, c, n = [int(i) for i in fin.readline().rstrip('\n').split()]
	# print r, c, n
	table = []
	l = []
	for i in xrange(r*c):
		l.append((0, [i]))
	table.append(l)

	for line in xrange(1, n):
		l = []
		for position in xrange(r*c):
			ref = stay(table[line-1], position, c)
			if position != 0 and l[position-1][0] < ref[0]:
				ref = l[position-1]
			l.append(ref)
		table.append(l)

	# print table
	# print table[n-1][r*c-1]
	answer += str(table[n-1][r*c-1][0])
	print answer
	fout.write(answer + '\n')

fin.close()
fout.close()