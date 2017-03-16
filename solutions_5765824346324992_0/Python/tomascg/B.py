import math

def valid_k(n,m_is,k):
	left_side = 0
	right_side = n-1
	for i in m_is:
		left_side += math.ceil(float(k)/i) 
	if left_side <= right_side:
		return True
	else:
		return False




def binary_search_on_k(n,m_is):
	denominator_max = 0
	for i in m_is:
		denominator_max += 1.0/i
	max_k = int((n-1.0)/denominator_max) + len(m_is)
	first = 0
	last = max_k
	largest_valid_k = 0
	while first<=last:
		mid = (first+last)/2
		if valid_k(n,m_is,mid):
			largest_valid_k = mid
			first = mid+1
		else:
			last = mid-1
	return largest_valid_k

def given_k_who_cuts(k,m_is,n):
	right_side = n-1
	left_side = 0
	for i in m_is:
		left_side += math.ceil(float(k)/i) 
	difference = right_side-left_side
	for i in range(0,len(m_is)):
		if k % m_is[i] == 0:
			if difference == 0:
				return i+1
			else:
				difference = difference-1




f = open("a.in", "r").read()

splitted_file = f.split("\n")[:]

lineCounter =1
amountOfLines = len(splitted_file)

case = 0

while(lineCounter < amountOfLines-1):
    case += 1
    firstLine = splitted_file[lineCounter]
    lineCounter += 1

    secondLine = splitted_file[lineCounter]
    lineCounter += 1
    B,n= [int(x) for x in firstLine.split(" ")]

    m_is = [int(x) for x in secondLine.split(" ")]   
    out = given_k_who_cuts(binary_search_on_k(n,m_is), m_is, n)
    print "Case "+ "#"+str(case) +": " + str(out)
    
    
