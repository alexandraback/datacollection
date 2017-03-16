import os
import sys

os.chdir(sys.path[0])

def reduce( str ):
	str = str.strip()
	if len(str) == 1 :
		return str
	else :
		charstr = str[0]
		for char in str[1:]:
			if char != charstr[-1] :
				charstr += char
		return charstr

def convert(str):
	str = str.strip()
	list = []
	if len(str) == 1:
		return [1]
	else :
		prev = str[0]
		cnt = 1
		for char in str[1:]:
			if char == prev :
				cnt += 1
			else :
				list.append(cnt)
				prev = char
				cnt = 1
		list.append(cnt)
		return list
	
def getminactionsfromstrings( strlist ):
	listofnumberlist = []
	actions = 0
	for str in strlist :
		listofnumberlist.append(convert(str))
	#print listofnumberlist
	for i in range(len(listofnumberlist[0])):
		list = [ j[i] for j in listofnumberlist ]
		#print list
		actions += getminactionsforlist(list)
		
	return actions
		
	
def getminactionsforlist(list):
	init = 0
	minimum = 0
	last_aim = 0
	for aim in range(min(list), max(list)+1):
		actions = 0
		for i in list :
			actions += abs(i-aim)
		#print actions
		if not init :
			init = 1
			minimum = actions
			last_aim = aim
		else :
			if actions > minimum :
				break
			else :
				minimum = actions
	#print "Min {}, aim {}".format(minimum,last_aim)

	return minimum

def possible( strlist ):
	list = []
	for str in strlist :
		list.append(reduce(str))
	#print list
	if len(list) == list.count(list[0]):
		return 1
	else :
		return 0
		
if len(sys.argv) > 1 :
	inputfile = sys.argv[1]
	outputfile = inputfile+"_output.txt"
else :
	inputfile = "input.txt"
	outputfile = "output.txt"
	
inputf = open(inputfile,"r")
outputf = open(outputfile,"w")

lines = inputf.readlines()
print "Number of tests = {}".format(lines[0])

numberoftests = int(lines[0])
lines = lines[1:]
for i in range(1,1+numberoftests) :
	nrlines = int(lines[0])
	lines = lines[1:]
	strlist = lines[0:nrlines]
	lines = lines[nrlines:]
	if possible(strlist) :
		print "Case #{}: {}".format(i,getminactionsfromstrings(strlist))
		print >>outputf,"Case #{}: {}".format(i,getminactionsfromstrings(strlist))
	else :
		print "Case #{}: {}".format(i,"Fegla Won")
		print >>outputf,"Case #{}: {}".format(i,"Fegla Won")

outputf.close()
