#written by wegnahz

def cross_product(x1, y1, x2, y2):
	return x1 * y2 - x2 * y1

fin = open("Logging.in", "r")
fout = open("Logging.out", "w")

T = int(fin.readline())
for t in range(T):
	n = int(fin.readline())
	x = []
	y = []
	for i in range(n):
		tokens = fin.readline().split(' ')
		x.append(float(tokens[0]))
		y.append(float(tokens[1]))
	
	#print points
	#hull = ConvexHull(points)
	result = []
	for i in range(n):
		min_nodes = n/2
		for j in range(n):
			if i != j:
				sum_positive = 0
				sum_negative = 0
				for k in range(n):
					if i != k and j != k:
						p = cross_product(x[j]-x[i], y[j]-y[i], x[k]-x[i], y[k]-y[i])
						if p < 0:
							sum_negative += 1
						elif p > 0:
							sum_positive += 1
				min_nodes = min(min_nodes, min(sum_positive, sum_negative))
		result.append(min_nodes)
	
	fout.write('Case #%d:\n' % (t+1))
	for i in range(n):
		fout.write('%d\n' % (result[i]))
	
