t = int(raw_input())

def check(L):
	return max(L)*2 <= sum(L)

for T in range(1,t+1):
	print 'Case #%d:'%T,
	n = int(raw_input())

	L = map(int,list(raw_input().split()))


	while sum(L) > 0:
		done = False
		for i in range(n):
			if L[i] == 0:
				continue
			L[i] -= 1
			if check(L):
				print chr(ord('A')+i),
				done = True
				break
			L[i] += 1
		if done:
			continue
		for i in range(n):
			for j in range(n):
				L[i] -= 1
				L[j] -= 1
				if L[i] >= 0 and L[j] >= 0 and check(L):
					print chr(ord('A')+i)+chr(ord('A')+j),
					done = True
					break
				L[i] += 1
				L[j] += 1
			if done:
				break
		if done == False:
			exit(1)
	print ''

