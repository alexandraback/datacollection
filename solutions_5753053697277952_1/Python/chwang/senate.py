
def step(num):
	assert(sum([n > sum(num)/2 for n in num]) == 0)
	#print num
	first = num.index(max(num))
	num[first] = num[first] - 1
	if sum(num) == 0:
		return num, first, -1

	second = num.index(max(num))
	num[second] = num[second] - 1
	if sum([n > sum(num)/2 for n in num]) == 0:
		return num, first, second
	else:
		num[second] = num[second] + 1
		return num, first, -1

def evacuate(num):
	seq = []
	base = ord('A')
	while sum(num) > 0:
		num, first, second = step(num)

		if second != -1:
			seq.append(chr(first + base) + chr(second + base))
		else:
			seq.append(chr(first + base))
	return seq


filename = 'A-large'
f_out = open(filename+'.out', 'w')
with open(filename+'.in') as f_in:
	T = int(f_in.readline())
	for t in xrange(T):
		N = f_in.readline()
		nums = f_in.readline().rstrip().split(' ')
		nums = [int(n) for n in nums]
		#print N, nums

		f_out.write('Case #' + str(t+1) + ': ')	
		result = evacuate(nums)
		for r in result:
			f_out.write(r + ' ')
		f_out.write('\n')

