from collections import OrderedDict

alpha = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def get_solution(n, string):
	sol = []
	d = {}
	nums = string.split()
	total = 0
	for i in range(n):
		d[alpha[i]] = int(nums[i])
		total += d[alpha[i]]
	while total > 2:
		# Case 1: Chuck two persons out.
		flag = False
		sorts = sorted(d, key=lambda(x): d[x])
		sorts.reverse()
		a, b = sorts[0], sorts[1]

		cutoff = (total-2)/2 + 1
		d[a] -= 1
		d[b] -= 1
 		remove = 2
		for j in d:
			if d[j] >= cutoff:
				remove = 1
				d[b] += 1
		k = [a,b]
		strs = ''
		for i in range(remove):
			if d[k[i]] == 0:
				d.pop(k[i])
			strs += k[i]
		sol.append(strs)
		total -= remove
	strs = ''
	for i in d:
		strs += i
	sol.append(strs)
	return ' '.join(sol)


t = int(raw_input())

for i in range(t):
        n = int(raw_input())
        string = raw_input()
        print "Case #%d: %s" % (i+1, get_solution(n, string))
