import sys

T = int(raw_input())

for t in range(1, T+1):
	N = int(raw_input())
	Ps = map(int, raw_input().split())

	ret = []

	while sum(Ps):
		max_p = max(Ps)
		if Ps.count(max_p) != 1:
			first = Ps.index(max_p)
			Ps[first] = max_p - 1

			if sum(Ps) == 0 or sum(Ps) == 2:
				ret.append([first])
			else:
				second = Ps.index(max_p)
				Ps[second] = max_p - 1
				ret.append([first, second])
		else:
			first = Ps.index(max_p)
			Ps[first] = max_p - 1

			max_p = max(Ps)
			if sum(Ps) == 0 or sum(Ps) == 2:
				ret.append([first])
			else:
				second = Ps.index(max_p)
				Ps[second] = max_p - 1
				ret.append([first, second])


	ret_str = ' '.join([ ''.join([ chr(ord('A')+i[j]) for j in range(len(i)) ]) for i in ret ])

	print 'Case #%d: %s' % (t, ret_str)
