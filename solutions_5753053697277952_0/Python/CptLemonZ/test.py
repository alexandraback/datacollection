infile = open('A-small-attempt1 (1).in', 'r')
outfile = open('test.out', 'w')

T = int(infile.readline())
letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

for t in range(1, T+1):
	N = int(infile.readline())
	lst = map(int, infile.readline().split(' '))

	ans = ''
	while sum(lst) > 2:
		m = max(lst)
		m_i = lst.index(m)
		ans += letters[m_i]
		lst[m_i] -= 1
		for x in lst:
			if x > sum(lst)/2:
				two = True
				m = max(lst)
				m_i = lst.index(m)
				ans += letters[m_i]
				lst[m_i] -= 1
		ans += ' '

	for i in range(len(lst)):
		if lst[i] == 1:
			ans += letters[i]

	outfile.write('Case #' + str(t) + ': ' + ans + '\n')