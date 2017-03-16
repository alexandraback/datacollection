#! /usr/bin/python

debug = False

def solve(input_data):
	fail_msg = "Fegla Won"
	n, strings = input_data

	groups = []
	sizes = []
	fail = False
	# reducing strings to groups
	for s in strings:
		g = [s[0]]
		size = [1]
		for i in xrange(1, len(s)):
			if s[i] == s[i-1]:
				size[-1] += 1
			else:
				size.append(1)
				g.append(s[i])

		if len(groups) > 0 and g != groups[-1]:
			fail = True
			break
		groups.append(g)
		sizes.append(size)

	if fail:
		return fail_msg

	if debug: print sizes

	res = 0

	gn = len(sizes[0])
	for i in xrange(gn):
		nums = []
		for size in sizes:
			nums.append(size[i])

		nums = sorted(nums)
		m = 1000*1000*1000

		b = nums[0]
		while b <= nums[-1]:
			tr = 0
			for j in xrange(n):
				tr += abs(b - nums[j])

			m = min(m, tr)
			b += 1

		res += m

	return str(res)


def read_input():
	n = int(raw_input())
	s = [raw_input() for i in xrange(n)]
	return (n, s)

def main():
	T = int(raw_input())
	for t in xrange(T):
		print "Case #%d: %s" % (t + 1, solve(read_input()))

if __name__ == "__main__":
	main()
