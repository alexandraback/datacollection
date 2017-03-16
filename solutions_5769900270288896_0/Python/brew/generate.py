import itertools  

def generate(R,C,N):
	X = []
	Y = []
	global_unh = (R-1)*C + (C-1)*R
	for i in range(R):
		X.append([])

	for i in range(R):
		for j in range(C):
			Y.append([i,j])
	

	all_subsets = list(itertools.combinations(Y, N))

	for k in all_subsets:	

		X = []
		for i in range(R):
			X.append([])
		for i in range(R):
			for j in range(C):
				if [i,j] in k:
					X[i].append(1)
				else:
					X[i].append(0)

	
		curr_unh = calc_unh(X,R,C)
		if curr_unh == 0:
			return 0
		else:
			if curr_unh < global_unh:
				global_unh = curr_unh

		

	print R,C,N,global_unh
	return global_unh


def calc_unh(X,R,C):
	unh = 0
	for i in range(R):
			for j in range(C):
				if i > 0:
					if X[i][j] == 1 and X[i-1][j] == 1:
						unh += 1
				if i < R-1:
					if X[i][j] == 1 and X[i+1][j] == 1:
						unh += 1 
				if j > 0:
					if X[i][j] == 1 and X[i][j-1] == 1:
						unh += 1 
				if j < C-1:
					if X[i][j] == 1 and X[i][j+1] == 1:
						unh += 1 

	unhappy = unh/2

	return unhappy


g = open("gen-data-final.txt","w")
for a in range(17):
	for b in range(17):
		if a*b <= 16:
			for x in range(a*b+1):
				g.write(str(a) + " " + str(b) + " " + str(x) + " " + str(generate(a,b,x))) 
				g.write("\n")