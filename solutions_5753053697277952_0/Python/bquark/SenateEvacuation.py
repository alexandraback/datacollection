fi = open("A-small-attempt0.in")
fo = open("A-small-attempt0.out", "w")

line = next(fi)
T = int(line)
for t in range(T):
	line = next(fi)
	N = int(line)
	line = next(fi)
	P = [int(f) for f in line.rstrip().split(' ')]
	for n in range(N):
		P[n] = [P[n], n]
	P = sorted(P, reverse=True)
	w = ""
	while(len(P)>0):
		if len(P)==2 and P[0][0]==P[1][0]:
			w += " " + chr(P[0][1]+65) + chr(P[1][1]+65)
			P[0][0] -= 1
			P[1][0] -= 1
			if P[0][0] == 0:
				break
		else:
			w += " " + chr(P[0][1]+65)
			P[0][0] -= 1
			if P[0][0] == 0:
				P.pop(0)
		k = 1
		while k < len(P) and P[k][0] > P[k-1][0]:
			P[k], P[k-1] = P[k-1], P[k]
			k += 1

	fo.write("Case #" + str(t+1) + ":" + str(w) + "\n")

fi.close()
fo.close()
