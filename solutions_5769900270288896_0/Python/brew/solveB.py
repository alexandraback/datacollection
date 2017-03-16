def solve(R,C,N):

	f = open("gen-data-final.txt","r")
	d = f.read().split("\n")
	for x in d:
		y = x.split(" ")

		if y[0] == R and y[1] == C and y[2] == N:
			return y[3]
	return 0

def dosolve(f,g):
	d = f.read().split("\n")
	n = int(d[0])

	j = 1
	for i in range(1,n+1):
		data = d[i].split(" ")
		R = data[0]
		C = data[1]
		N = data[2]

		print R,C,N

		g.write ("Case #" + str(i) + ": " + str(solve(R,C,N)) + "\n")

# def solve_large():
# 	g = open("A-large-out.txt","w")
# 	f = open("A-large.in","r")
# 	dosolve(f,g)

def solve_small():
	g = open("B-small-out.txt","w")
	f = open("B-small-attempt1.in","r")
	dosolve(f,g)

def solve_examples():
	g = open("B-eg-out.txt","w")
	f = open("B-eg.in","r")
	dosolve(f,g)
	
# solve_examples()
solve_small()
# solve_large