import heapq as heap

def calc(t):
	global m
	#print t
	#print list(map(lambda x: t/x + (t%x != 0), m))
	return sum(map(lambda x: t/x + (t%x != 0), m))

for case_no in range(int(raw_input())):
	b, n = map(int, raw_input().split())
	m = list(map(int, raw_input().split()))

	if n <= b:
		ans = n
	else:
		mx = max(m)
		lo, hi = 0, n*(mx+1)
		while True:
			mid = (lo + hi)/2
			nn = calc(mid)
			if n-b <= nn < n:
				n -= nn
				#print list(enumerate(m))
				h = map(lambda x: ((0 if mid%x[1] == 0 else (x[1] - mid%x[1]))+mid, x[0]), enumerate(m))
				heap.heapify(h)
				while True:
					#print "mid %d rest %d" %(mid, n)
					#print h
					x = heap.heappop(h)
					n -= 1
					if n == 0:
						ans = x[1]+1
						break
					mid = x[0]
					#print x[1]
					heap.heappush(h, (m[x[1]]+mid, x[1]))

				break
			if nn >= n:
				hi = mid
			else:
				lo = mid
				
	
	print "Case #%d: %d" % (case_no+1, ans)
