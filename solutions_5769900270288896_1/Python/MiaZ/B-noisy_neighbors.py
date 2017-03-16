argT = int(raw_input())

def even(r, c):
	ret = [0, 0, 0, 0, 0]
	ret[0] = r * c / 2
	ret[2] = 2
	ret[3] = r + c - 4
	ret[4] = r * c - sum(ret[0:4])
	return ret

def oddp(r, c):
	ret = [0, 0, 0, 0, 0]
	ret[0] = (r * c + 1)/ 2
	ret[3] = r + c - 2
	ret[4] = r * c - sum(ret[0:4])
	return ret

def oddn(r, c):
	ret = [0, 0, 0, 0, 0]
	ret[0] = (r * c - 1)/ 2
	ret[2] = 4
	ret[3] = r + c - 6
	ret[4] = r * c - sum(ret[0:4])
	return ret

def snge(l):
	ret = [0, 0, 0, 0, 0]
	ret[0] = l / 2
	ret[1] = 1
	ret[2] = l - sum(ret[0:2])
	return ret

def sngo(l):
	ret = [0, 0, 0, 0, 0]
	ret[0] = (l + 1) / 2
	ret[2] = l - sum(ret[0:2])
	return ret

def accu(res, n):
	sum = 0
	j = 0
	while n > 0:
		if n <= res[j]:
			sum += j * n
			n -= n
		else:
			sum += j * res[j]
			n -= res[j]
		j += 1
	return sum

def geta(r, c, n):
	if min([r, c]) < 2:
		l = max([r, c])
		if l % 2 == 0:
			return accu(snge(l), n)
		else:
			return accu(sngo(l), n)
	else:
		p = r * c
		if p % 2 == 0:
			return accu(even(r, c), n)
		else:
			return min([accu(oddp(r, c), n), accu(oddn(r, c), n)])
	return None # Should not happen

for repeat in xrange(1, argT + 1):
	args = raw_input().split()
	argR, argC, argN = int(args[0]), int(args[1]), int(args[2])
	print "Case #%d:" % repeat,

	uns = geta(argR, argC, argN)
	print uns