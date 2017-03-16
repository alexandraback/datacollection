def takeOneAction(a):
	maxNum = max(a)
	maxInd = [i for i in range(len(a)) if a[i] == maxNum]
	if maxNum == 1 and len(maxInd) == 3:
		return maxInd[0 : 1]
	else:
		return maxInd[0 : 2]

def evac(a):
	results = []
	while max(a) > 0:
		res = takeOneAction(a)
		for i in res:
			a[i] -= 1
		results += [''.join(chr(65 + k) for k in res)]
	return results 

if __name__ == '__main__':
	fin = open('A-small-attempt0.in', 'r')
	fout = open('out.txt', 'w+')
	T = int(fin.readline())
	for i in range(T):
		n = int(fin.readline())
		a = [int(x) for x in fin.readline().split()]
		fout.write('Case #{0}: {1}\n'.format(i + 1, ' '.join(evac(a))))
	fin.close()
	fout.flush()
	fout.close()
