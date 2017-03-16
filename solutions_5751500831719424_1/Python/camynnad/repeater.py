import csv
from itertools import product
import numpy as np

def lengthen(string,pos):
    return string[:pos+1]+string[pos:]

def shorten(string,pos):
    return string[:pos]+string[pos+1:]

def minimal(string):
    result = string[0]
    for i in string[1:]:
	if result[-1] != i:
	    result += i
    return result

def partition(string):
    result,temp = [],string[0]
    for i in range(1,len(string)):
	if string[i] != temp[0]:
	    result.append(temp)
	    temp = string[i]
	else:
	    temp += string[i]
    result.append(temp)
    return result

def allthesame(inList):
    first = inList[0]
    for i in range(1,len(inList)): 
	if inList[i] != first:
	    return False
    return True

def getCounts(inList):
    counts = 0
    count2 = np.array([[len(x) for x in y] for y in inList])
    for i in range(len(inList[0])):
	temp = count2[:,i]
	tmedian = int(np.median(temp))
	for j in range(len(temp)):
	    counts += abs(temp[j]-tmedian)
	#print sum(temp),np.median(temp),temp
	#counts += sum(temp)-int(np.median(temp))*len(inList)
    return counts

def makeDecisions(raw,minim,part):
    if allthesame(raw):
	return 0
    elif not allthesame(minim):
	return 'Fegla won'
    else:
	return getCounts(part)


def charging(infile):
    reader = csv.reader(open(infile,'r'),delimiter=' ')
    t,t0 = int(reader.next()[0]),0
    while t0 < t:
	t0 += 1
	n = int(reader.next()[0])
	words,mini,part = [],[],[]
	for i in range(n):
	    inp = reader.next()[0].strip()
	    mini.append(minimal(inp))
	    part.append(partition(inp))
	    words.append(inp)
	rstr = makeDecisions(words,mini,part)

	#print 'Case #%s: %0.7f' % (t0,float(rstr))
	print 'Case #%s: %s' % (t0,str(rstr))

if __name__ == '__main__':
    import argparse
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('infile',metavar='infile',type=str)
    args = ap.parse_args()
    charging(args.infile)
