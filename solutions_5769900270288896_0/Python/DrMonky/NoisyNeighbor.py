import itertools

fi = open('B-small-attempt0.in', 'r')
fo = open('output', 'w')

T = int(fi.readline())

def calc(r,c,n,case):
 	matrix = []
 	for i in range(r):
 		matrix.append([])
 		for j in range(c):
 			if i*c + j in case:
 				matrix[i].append(True)
 			else:
 				matrix[i].append(False)
 	result = 0
 	for i in range(r):
 		for j in range(c):
 			if matrix[i][j]:
 				if i+1<r and matrix[i+1][j]:
 					result += 1
 				if j+1<c and matrix[i][j+1]:
 					result += 1
 	return result
 			

for test in range(T):
	(r,c,n) = list(map(int, fi.readline().split(' ')))
	initialCase = range(r*c)
	cases = list(itertools.combinations(initialCase,n))
	res = 1000000000;
	for case in cases:
		res = min(res, calc(r,c,n,case))
	fo.write("Case #%i: %i\n" % (test+1, res))