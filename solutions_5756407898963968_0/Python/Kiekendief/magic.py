#read test cases

import os
import sys

os.chdir(sys.path[0])

#list of testcases
list = []

def findRow ( nr, mx1 ) :
	for i in range(4) :
		for j in range (4) :
			if nr == mx1[i][j] :
				return i

def equalsRow ( row1, row2 ):
	ret = True
	for i in range(len(row1)):
		if row1[i] != row2[i] :
			ret = False
	return ret
				
def movedToRow( row, mx1, mx2) :
	ret = True
	moved_to_row = []
	list_nr = mx1[row]
	for nr in list_nr :
		moved_to_row.append(findRow(nr, mx2))
	
	return moved_to_row

''' unitTest	
print findRow(1, [[1,2,3,4], [5,6,7,8], [9,10,11,12], [13,14,15,16]] )
print findRow(9, [[1,2,3,4], [5,6,7,8], [9,10,11,12], [13,14,15,16]] )
print equalsRow([1,2,3,4], [5,6,7,8])
print equalsRow([1,2,3,4], [1,2,3,4])
print equalsRow([1,2,3,4], [1,2,3,5])
'''

input = open("input.txt","r")
lines = input.readlines()

def getRowFromLine(line) :
	list = line.split(" ")
	list = [ int(i) for i in list ]
	return list

def getMatrixFromLines(lines):
	mx = []
	for line in lines:
		mx.append(getRowFromLine(line))
	return mx

if len(lines) :
	#Test length of lines
	nrOfTests = int(lines[0])
	print len(lines) == nrOfTests*10+1
	row = 1
	for test in range(nrOfTests) :
		answer1 = int(lines[row])
		row+=1
		mx1 = getMatrixFromLines(lines[row:row+4])
		row+=4
		answer2 = int(lines[row])
		row+=1
		mx2 = getMatrixFromLines(lines[row:row+4])
		row+=4
	
		#Get moved to row
		moved_to_row = movedToRow(answer1-1, mx1, mx2)
		#print moved_to_row
		if moved_to_row.count(answer2-1) == 0 :
			print "Case #"+str(test+1)+": Volunteer cheated!"
		elif moved_to_row.count(answer2-1) == 1 :
			print "Case #"+str(test+1)+": "+str(mx1[answer1-1][moved_to_row.index(answer2-1)])
		else :
			print "Case #"+str(test+1)+": Bad magician!"
		
		'''
		for i in range(4) :
			print ""
			teststr = ""
			for j in range(4) :
				teststr += str(mx1[i][j])
				teststr += " "
			print teststr
		for i in range(4) :
			print ""
			teststr = ""
			for j in range(4) :
				teststr += str(mx2[i][j])
				teststr += " "
			print teststr	
		'''
	
	
		