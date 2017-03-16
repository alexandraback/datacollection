import numpy as np

def format_solution(solution):

	ret = []

	def alpha(i):
		return chr(ord('A')+i)

	for item in solution:
		if len(item)==2:
			ret.append(alpha(item[0])+alpha(item[1]))
		else:
			ret.append(alpha(item[0]))

	return ' '.join(ret)

def solve(arr,p1,p2):
	ops = [(p1,p2)]
	now = np.array([0]*len(arr))
	now[p1] = 1
	now[p2] = 1

	while any(now != arr):
		m = np.min(now[now!=arr])
		idxs = [i for i,x in enumerate(now) if x==m and arr[i]!=x]
		if len(idxs)>=2:
			now[idxs[0]]+=1
			now[idxs[1]]+=1
			ops.append((idxs[0],idxs[1]))
		elif len(idxs)==1:
			now[idxs[0]]+=1
			ops.append((idxs[0],))
		else:
			return []

		assert( all( (1.0*now / np.sum(now)) <= 0.5))


	assert(all(now == arr))
	return ops[::-1]



arr = np.random.randint(1,1000//26,size=26)

T = int(raw_input())

for i in range(T):
	n = int(raw_input())
	xs = np.array([ int(x) for x in raw_input().split()])

	print 'Case #{}: {}'.format(i+1,format_solution(solve(xs,0,1)))

