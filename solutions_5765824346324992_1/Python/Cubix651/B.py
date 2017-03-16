
def number(v, m):
	r = 0
	for x in m:
		r += (v / x) + 1
	return r

def compute(v, m, n):
	l = []
	for i, x in enumerate(m):
		if v % x == 0:
			l.append(i+1)
	a = number(v, m) - n + 1
	return l[-a]

def solve(n, m):
	beg = 0
	end = min(m) * n;
	while beg < end:
		mid = (beg + end) / 2
		if number(mid, m) >= n:
			end = mid
		else:
			beg = mid+1
	return compute(beg, m, n)

def main():
	t = int(raw_input())
	for tt in range(1, t+1):
		b, n = map(int, raw_input().split(' '))
		m = map(int, raw_input().split(' '))
		print 'Case #{0}: {1}'.format(tt, solve(n, m))

if __name__ == '__main__':
	main()