
def solve1(m):
	p = 0
	r = 0
	for x in m:
		r += max(p - x, 0)
		p = x
	return r

def enough(v, m):
	s = 0
	for x in m:
		if s > x:
			return False
		s = max(x - v, 0)
	return True

def count(v, m):
	s = 0
	r = 0
	for x in m[:-1]:
		s = max(x - v, 0)
		r += x-s
	return r

def solve2(m):
	beg = 0
	end = max(m)
	while beg < end:
		mid = (beg + end) / 2
		if enough(mid, m):
			end = mid
		else:
			beg = mid+1
	return count(beg, m)

def main():
	t = int(raw_input())
	for tt in range(1, t+1):
		raw_input()
		m = map(int, raw_input().split(' '))
		print 'Case #{0}: {1} {2}'.format(tt, solve1(m), solve2(m))

if __name__ == '__main__':
	main()