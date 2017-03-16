import heapq


def firstAvail(minsLeft,m):
	try:
		return minsLeft.index(m)
	except:
		return -1

with open('B-small-attempt3.in') as f:
	with open('B-small-3.out','w') as of:
		t = int(f.readline())
		for case in range(1,t+1):
			b,n = list(map(int,f.readline().split()))
			ms = list(map(int,f.readline().split()))
			minsLeft = []
			#Initial Reduction Step - Dumb, but enough for the small test
			mult = 1
			for i in range(b):
				mult *= ms[i]

			period = sum([int(mult/a) for a in ms])
			n = n % period
			for i in range(b):
				heapq.heappush(minsLeft,(0,i))
			m = 0
			minpair = heapq.heappop(minsLeft)
			for i in range(n - 1):
				minpair = heapq.heappushpop(minsLeft,(minpair[0] + ms[minpair[1]], minpair[1]))
			of.write("Case #{}: {}\n".format(case,minpair[1] + 1))