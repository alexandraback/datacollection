def main():
	t = int(raw_input())  # read a line with a single integer
	alph = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
	for i in xrange(1, t + 1):
		N = raw_input()
		P = [int(s) for s in raw_input().split(" ")]
		strout = ''
		while not isZero(P):
			maxi = getMax(P)
			maxi2 = getMax2(P)
			if maxi != maxi2 and P[maxi] == P[maxi2] and sum(P) != 3:
				strout += alph[maxi2]
				P[maxi2] -= 1
			P[maxi] -= 1
			strout += alph[maxi] + ' '

		print "Case #{}: {}".format(i, strout)

def isZero(P):
	for p in P:
		if p != 0:
			return False
	return True

def getMax(P):
	max = P[0]
	maxi = 0
	for i in range(len(P)):
		if P[i] > max:
			max = P[i]
			maxi = i
	return maxi

def getMax2(P):
	max = P[0]
	maxi = 0
	for i in range(len(P)):
		if P[i] >= max:
			max = P[i]
			maxi = i
	return maxi

main()