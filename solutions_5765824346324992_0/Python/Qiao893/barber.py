def gcd(a, b):
    r = a % b
    if r:
        return gcd(b, r)
    else:
        return b

def lcm(a, b):
    return a * b / gcd(a, b)

def lcmAll(seq):
    return reduce(lcm, seq)



if __name__ == '__main__':
	f = open('B-small-attempt1.in', 'r')
	g = open('output.txt', 'w')
	T = int(f.readline())

	for caseNum in range(T):
		print caseNum
		line1 = f.readline()
		[B,N] = [int(c) for c in line1.split()]

		line2 = f.readline()
		times = [int(c) for c in line2.split()]
		
		LCM = lcmAll(times)
		nn = 0
		for ti in times:
			nn = nn + LCM/ti

		if N%nn != 0:
			N = N%nn
		else:
			N = nn
		
		remain_time = [0 ] * len(times)
		time = 0
		i = 1
		x = 0
		while(i < N):
			if time is 0:
				for j  in range(len(remain_time)):
					if remain_time[j] == 0:
						remain_time[j] = times[j]
						break
				time = min(remain_time)
				i = i+1
			else:
				remain_time = [x-time for x in remain_time]
				time = min(remain_time)
		x = 0
		time = min(remain_time)
		for j in range(len(remain_time)):
			if remain_time[j] == time:
				x = j+1
				break		
		
		g.write('Case #' + str(caseNum+1) + ': '+ str(int(x)) + '\n')
		#print 'Case #',str(caseNum+1) , ': ' , str(int(x)),str(int(y)) 

	f.closed
	g.closed
