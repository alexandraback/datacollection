#!/usr/bin/env python

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1,total_T+1):
		N = int(f.readline().rstrip('\n'))
		s = {}
		for i in xrange(N):
			s[i] = list(f.readline().rstrip('\n'))

		# print N, s
		# print run(s, N)
		

		# print N,L
		# print outlets
		# print devices
		# print find(outlets, devices)

		print 'Case #{}: {}'.format(T, run(s, N))

def run(s, N):

	if all(s[x] == [] for x in s):
		return 0
	if any(s[x] == [] for x in s):
		return 'Fegla Won'
	ss = {}
	for i in xrange(N):
		ss[i], s[i] = split_by_1(s[i])


	if any(ss[x][0]!=ss[0][0] for x in ss):
		return 'Fegla Won'
	else:
		c = count(ss)
		# print c
		r_c = run(s, N)
		if r_c !='Fegla Won':
			return c+r_c
		else:
			return  r_c

def count(ss):
	sum_ = sum(len(ss[x]) for x in ss)
	max_ = max(len(ss[x]) for x in ss)
	return min(sum(abs(i-len(ss[x])) for x in ss) for i in xrange(max_+1))

def split_by_1(sss):
	new_sss = []
	for i in xrange(len(sss)):
		if sss[i] != sss[0]:
			new_sss, sss = sss[:i], sss[i:]
			return new_sss, sss



	return sss, []


def find(outlets, devices):
	sets = [set(o^d for o in outlets) for d in devices]
	r = sets.pop()
	while sets != []:
		r &= sets.pop()

	if r ==set():
		return 'NOT POSSIBLE'
	return min(bin(x).count('1') for x in r)


if __name__ == '__main__':
	main()