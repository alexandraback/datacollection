from sys import stdin
import sys

num_cases = int(stdin.readline().rstrip())
#print num_cases

for i in range(0, num_cases):

	row1 = int( stdin.readline().rstrip() )-1
	board1 = []
	for j in range(0,4):
		st = stdin.readline().rstrip()
		st = st.split()
		st = [int(s) for s in st]
		board1.append( st )
	#print board1
	
	row2 = int( stdin.readline().rstrip() )-1
	board2 = []
	for j in range(0,4):
		st = stdin.readline().rstrip()
		st = st.split()
		st = [int(s) for s in st]
		board2.append( st )
	#print board2
	
	#print board1[row1]
	#print board2[row2]
	
	result = set(board1[row1]).intersection(set(board2[row2]))
	if len(result) == 1:
		print "Case #" + str(i+1) + ": " + str(list(result)[0])
	elif len(result) > 1:
		print "Case #" + str(i+1) + ": " + "Bad magician!"
	elif len(result) == 0:
		print "Case #" + str(i+1) + ": " + "Volunteer cheated!"
	