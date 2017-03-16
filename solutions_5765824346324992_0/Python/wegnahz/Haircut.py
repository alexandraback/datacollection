#written by wegnahz

fin = open("Haircut.in", "r")
fout = open("Haircut.out", "w")

T = int(fin.readline())
for t in range(T):
	tokens = fin.readline().split(' ')
	B = int(tokens[0])
	N = int(tokens[1])
	tokens = fin.readline().split(' ')
	M = [int(s) for s in tokens]
	left = 0
	right = 100000 * 1000000000 / 1000
	while left <= right:
		mid = (left + right) / 2
		n_customers = 0
		min_idx = -1
		min_wait = 100000
		for i in range(B):
			n_customers += (mid+M[i]-1) / M[i]
		if n_customers > N-1:
			right = mid-1
		else:
			left = mid + 1
	wait_list = []
	cnt = 0
	for i in range(B):
		cnt += (right+M[i]-1) / M[i]
		wait_time = (right+M[i]-1) / M[i] * M[i] - right
		if wait_time == 0:
			wait_list.append(i)
	print right, cnt, N
	sorted_list = sorted(wait_list)
	fout.write('Case #%d: %d\n' % (t+1, sorted_list[N-cnt-1]+1))
