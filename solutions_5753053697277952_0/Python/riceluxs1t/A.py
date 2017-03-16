def solve(senate_count, n):
	
	is_done = True
	ans = []

	while n > 0:
		f, s = find_max_two(senate_count)

		if n - 2 == 1:
			senate_count[f] -= 1
			n -= 1
			ans.append(f)
		else:
			senate_count[f] -= 1
			senate_count[s] -= 1
			n -= 2
			ans.append(f + s)
		if n == 1:
			break
	if n == 0:
		return ans
	elif n == 1:
		f, s = find_max_two(senate_count)
		ans.append(f)
		return ans
	raise Exception('NOT!')

def find_max_two(senate_count):

	f = -1
	f_idx = None
	s = -1
	s_idx = None

	for k, v in senate_count.iteritems():
		if v > f:
			f = v
			f_idx = k

	for k, v in senate_count.iteritems():
		if k == f_idx: continue
		if v > s:
			s = v
			s_idx = k

	return f_idx, s_idx

# print solve({'A': 2, 'B':2}, 4)
# print solve({'A': 3, 'B': 2, 'C': 2}, 7)
# print solve({'A': 1, 'B': 1, 'C': 2}, 4)
# print solve({'A': 2, 'B': 3, 'C':1}, 6)
alpha = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'


f_out = open('A_output.txt', 'w')
f_in = open('A-small-attempt0.in', 'r')

lines = [line.strip() for line in f_in.readlines()][1:]
idx_f = 1
for idx in range(0, len(lines), 2):
	print 'i get here'
	senates = map(int, lines[idx+1].split())
	n = sum(senates)
	print n, senates
	senate_count = {}

	for i in range(len(senates)):
		senate_count[alpha[i]] = senates[i]
	print senate_count
	s = solve(senate_count, n)
	print 'ans found'
	print s
	ans = ' '.join(s)
	f_out.write("Case #{0}: {1}\n".format(idx_f, ans))
	idx_f += 1

f_out.close()