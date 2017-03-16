# -*- coding: utf-8 -*-


def alpha(p):
	return chr(p + 65)


def balanced(ps):
	total = sum(ps)
	if not total:
		return True
	for p in ps:
		if p / total > 0.5:
			return False
	return True


def solve(n, ps):
	plans = []
	while True:
		s = sum(ps)
		if not s:
			break
		plan = ''
		flag = False
		for i in range(n):
			if flag:
				break
			if not ps[i]:
				continue
			ps[i] -= 1
			for j in range(n):
				if flag:
					break
				if not ps[j]:
					continue
				ps[j] -=1
				if balanced(ps):
					plan += alpha(i) + alpha(j)
					flag = True
					break
				else:
					ps[j] += 1
			if flag:
				break
			else:
				ps[i] += 1
		if plan:
			plans.append(plan)
			continue
		for i in range(n):
			if not ps[i]:
				continue
			ps[i] -= 1
			if balanced(ps):
				plan += alpha(i)
				break
			else:
				ps[i] += 1
		plans.append(plan)
	return ' '.join(plans)


if __name__ == '__main__':
	outfile = open('a.out', 'w')
	T = int(input())
	for t in range(1, T + 1):
		n = int(input())
		ps = [int(p) for p in input().split(' ')]
		answer = solve(n, ps)
		outfile.write("Case #{}: {}\n".format(t, answer))
