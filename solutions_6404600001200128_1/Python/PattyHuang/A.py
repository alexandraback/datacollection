import sys
[T, N] = [0, 0]
cnt = 0
for line in sys.stdin:
	if T == 0:
		T = int(line.split("\n")[0])
	elif N == 0:
		N = int(line.split("\n")[0])
	else:
		[case1_cnt, case2_cnt] = [0, 0]
		rate = 0
		mi = map(int, line.split("\n")[0].split(' '))
		#case1
		for i in range(0, N-1):
			if mi[i+1] - mi[i] < 0:
				case1_cnt += abs(mi[i+1] - mi[i])
				if abs(mi[i+1] - mi[i]) > rate:
					rate = abs(mi[i+1] - mi[i])
		#case2
		for i in range(0, N-1):
			if mi[i] - rate <= 0:
				case2_cnt += mi[i]
			elif mi[i] - rate > 0:
				case2_cnt += rate
		cnt += 1	
		N = 0
		print "Case #{0}: {1} {2}".format(cnt, case1_cnt, case2_cnt)