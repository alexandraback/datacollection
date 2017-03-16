
with open('A-large.in') as f:
	with open('A-large.out','w') as of:
		t = int(f.readline())
		for case in range(1,t+1):
			n = int(f.readline())
			nums = list(map(int,f.readline().split()))
			totalneg = 0
			biggestgap = 0
			m2count = 0
			for i in range(n-1):
				if nums[i] > nums[i + 1]:
					gap = nums[i] - nums[i + 1] 
					totalneg += gap
					if gap > biggestgap:
						biggestgap = gap
			curr = nums[0]
			for i in range(1,n):
				if curr - biggestgap < 0:
					m2count += curr
				else:
					m2count += biggestgap
				curr = nums[i]

			of.write("Case #{}: {} {}\n".format(case,totalneg,m2count))