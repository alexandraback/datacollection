input_file = 'evacuate_senate.in'
SHIFT = 65

with open(input_file, 'rb') as inf:
	t = int(inf.readline())
	for i in xrange(t):
		n = int(inf.readline())
		ps = map(int, inf.readline().split())
		plan = []
		# index -> uppercase-letter: chr(i + 65)
		while sum(ps) > 0:
			curr_max = max(ps)
			curr_max_idx = ps.index(curr_max)
			curr_evac = chr(curr_max_idx + SHIFT)

			ps[curr_max_idx] -= 1
			curr_sum = sum(ps)
			next_max = max(ps)
			next_max_idx = ps.index(next_max)
			if next_max > curr_sum*0.5:
				curr_evac += chr(next_max_idx + SHIFT)
				ps[next_max_idx] -= 1
			plan.append(curr_evac)
		print 'Case #{0}: {1}'.format(i+1,
									  ' '.join(plan))