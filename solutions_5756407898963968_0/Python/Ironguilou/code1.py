
import sys

#fileName = "test"
fileName = "A-small-attempt0"

fin = open(fileName + ".in")
fout = open(fileName + ".out", 'w')

NCases = int(fin.readline())
sys.stderr.write("NCases = " + str(NCases) + "\n")

for nline in range(0, NCases) :
	print "\n############################"
	print "# Case " + str(nline)
	
	row1 = int(fin.readline().strip())
	for i in range(4) :
		if i == row1 - 1 :
			cards1 = map(int, fin.readline().strip().split())
		else :
			fin.readline()
		
	row2 = int(fin.readline().strip())
	for i in range(4) :
		if i == row2 - 1 :
			cards2 = map(int, fin.readline().strip().split())
		else :
			fin.readline()
	
	possibleCards = []
	for c in cards1 :
		if c in cards2 :
			possibleCards.append(c)
	
	if len(possibleCards) == 0 :
		r = "Volunteer cheated!"
	elif len(possibleCards) == 1 :
		r = possibleCards[0]
	else :
		r = "Bad magician!"
	
	fout.write("Case #" + str(nline+1) + ": " + str(r) + "\n")

fin.close()
fout.close()