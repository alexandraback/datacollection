def shrink(s):
	x = []
	curr = ''
	tab = []
	add = 1
	for i in s:
		if i != curr:
			x.append(i)
			if curr != '':
				tab.append(add)
				add = 1
		else:
			add += 1
		curr = i
	tab.append(add)
	return x, tab

def walk(s1, s2):
	i = 0
	j = 0
	res = 0
	while(i < len(s1) and j < len(s2)):
		if s1[i] == s2[j]:
			i += 1
			j += 1
		else:
			if j ==0 and i ==0:
				res = -1
				break
			if s2[j] == s2[j-1]:
				res += 1
				j += 1
			elif s1[i] == s1[i-1]:
				res += 1
				i += 1
			else:
				res = -1
				break
	return res

def median(l):
	minl = min(l)
	maxl = max(l)
	oper = -1
	for m in range(minl, maxl+1):
		mmm = 0
		for i in l:
			mmm += abs(i-m)
		if oper == -1 or oper > mmm:
			oper = mmm
	return oper 



def solve():
	#f = open("in.txt", 'r')
	f = open("A-small-attempt0.in.txt", 'r')
	T = int(f.readline())
	for t in range(T):
		N = int(f.readline())
		res = 0

		if N == 2:
			l1 = f.readline()
			l2 = f.readline()
			res = walk(l1, l2)
			if res == -1:
				print "Case #%i:" % (t+1), 'Fegla Won'
			else:
				print "Case #%i:" % (t+1), res
		else:
			l = []
			tab = []
			for i in range(N):
				l.append(f.readline())
			[x0, tab0] = shrink(l[0])
			tab.append(tab0)
			for i in range(1,N):
				[x1, tab1] = shrink(l[i])
				tab.append(tab1)
				if x1 != x0:
					res = -1
					break
			if res == -1:
				print "Case #%i:" % (t+1), 'Fegla Won'
			else:
				res = 0
				for i in range(len(tab0)):
					l = [tab[k][i] for k in range(N)]
					res += median(l)
				print "Case #%i:" % (t+1), res

solve()