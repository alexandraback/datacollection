



if __name__ == '__main__':
	f = open('A-large.in', 'r')
	g = open('output.txt', 'w')
	T = int(f.readline())

	for caseNum in range(T):
		line1 = int(f.readline())
		line2 = f.readline()
		nums = [int(c) for c in line2.split()]
		x = 0
		for i in range(len(nums)-1):
			if(nums[i+1]<nums[i]):
				x = x + nums[i] - nums[i+1]
		y = 0
		min_dif = 0		
		for i in range(len(nums)-1):
			if(nums[i+1] < nums[i]):
				min_dif = max(min_dif,nums[i]-nums[i+1])

		for i in range(len(nums)-1):
			if(nums[i] < min_dif):
				y = y + nums[i]
			else:
				y = y + min_dif

		g.write('Case #' + str(caseNum+1) + ': ' + str(int(x))+" "+str(int(y)) + '\n')
		#print 'Case #',str(caseNum+1) , ': ' , str(int(x)),str(int(y)) 

	f.closed
	g.closed
