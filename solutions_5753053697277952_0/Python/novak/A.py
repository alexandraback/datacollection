test_cases = int(raw_input())
for test_case in xrange(1, test_cases + 1):
	parties = int(raw_input())
	senators = [int(x) for x in raw_input().split(' ')]

	steps = []
	while sum(senators) > 0:
		step = ''

		m = max(senators)
		i = senators.index(m)
		step += chr(ord('A') + i)
		senators[i] -= 1

		m = max(senators)
		if m > 0:
			i = senators.index(m)
			senators[i] -= 1

			new_m = max(senators)
			if new_m <= sum(senators) - new_m:
				step += chr(ord('A') + i)
			else:			
				senators[i] += 1

		steps.append(step)

	print 'Case #{}: {}'.format(test_case, ' '.join(steps))