import sys
import os
from operator import itemgetter, attrgetter, methodcaller

inputFile = 'A-large.in'
outputFile = 'A-large.out'

f = open(inputFile, 'r')
fout = open(outputFile, 'w')
T = f.readline()
#print T
T = int(T)

for cases in range(1, T+1):
	n = int(f.readline())
	line = f.readline().split()
	records = []
	curr = 0
	count = 0
	#print line
	for s in line:
		curr = curr + 1
		records.append((curr, int(s)))
		count = count + int(s)
	#print records
	fout.write('Case #' + str(cases) + ': ')
	
	if n==2:
		fout.write('AB')
		for i in range(2, records[0][1]+1):
			fout.write(' AB')
		fout.write('\n')
	else:
		for i in range(1, count):
			records = sorted(records, key=itemgetter(1), reverse=True)
			if i + 2 > count:
				fout.write(chr(records[0][0] + 64) + chr(records[1][0] + 64) + '\n')
				break
			fout.write(chr(records[0][0] + 64) + ' ')
			records[0] = records[0][:1] + (records[0][1] - 1,)
		
		