#written by wegnahz

fin = open("Mushroom Monster.in", "r")
fout = open("Mushroom Monster.out", "w")

T = int(fin.readline())
for t in range(T):
	n = int(fin.readline())
	a = [int(s) for s in fin.readline().split(' ')]
	
	#method 1
	sum_1 = 0
	for i in range(1, n):
		sum_1 += max(a[i-1]-a[i], 0)
	
	#method 2
	max_gap = 0
	for i in range(1, n):
		max_gap = max(max_gap, a[i-1]-a[i])
	sum_2 = 0
	for i in range(n-1):
		sum_2 += min(max_gap, a[i])
		
	fout.write('Case #%d: %d %d\n' % (t+1, sum_1, sum_2))
