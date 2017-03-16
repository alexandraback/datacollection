
import sys

#fileName = "test"
#fileName = "A-small-attempt0"
fileName = "A-large"

fin = open(fileName + ".in")
fout = open(fileName + ".out", 'w')

NCases = int(fin.readline())
sys.stderr.write("NCases = " + str(NCases) + "\n")

for nline in range(0, NCases) :
	print "\n############################"
	print "# Case " + str(nline)
	
	N = int(fin.readline().strip())
	letters = [] # letters
	ns = []
	possible = True
	for i in range(N) :
		s = fin.readline().strip()
		print s
		
		l = s[0]
		n = [1]
		letters2 = [l]
		for k in range(1, len(s)) :
			if s[k] == l :
				n[-1] += 1
			else :
				l = s[k]
				letters2.append(l)
				n.append(1)
		ns.append(n)
		if i == 0 :
			letters = letters2
		else :
			if letters != letters2 :
				possible = False
	
	print letters, possible
	print ns
	
	if possible :
		ret = 0
		nl = len(ns[0])
		for i in range(nl) :
			ni = sorted([ns[j][i] for j in range(N)])
			nOpt = ni[N/2]
			print ni, nOpt
			
			ret += sum([abs(n - nOpt) for n in ni])
			
	else :
		ret = "Fegla Won"
	
	print "ret", ret
	
	fout.write("Case #" + str(nline+1) + ": " + str(ret) + "\n")

fin.close()
fout.close()