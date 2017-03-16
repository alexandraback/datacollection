#! /usr/bin/env python
import math


#################################################################################################

def parseInputData(problem, s_input, s_id):
	finput = open(problem + '-' + s_input + '-' + s_id + '.in','r')
	nCase = int(finput.readline().strip())
	inputList = finput.readlines()	
	finput.close()
	return nCase, inputList

#################################################################################################

def writeOutput(result, problem, s_input, s_id):
	foutput = open(problem + '-' + s_input + '-' + s_id + '.out','w')
	foutput.writelines(result)
	foutput.close()
	
#################################################################################################

def StrToNumList(s):
	s = s.strip()
	return [int(x) for x in s.split()]

def StrToNum(s):
	return int(s.strip())

def StrToNum(s):
	return int(s.strip())

#################################################################################################

def reduce_string(s):
	d = []
	result = ''
	for c in s:
		if result and result[-1] == c:
			d[-1] += 1
		else:
			result += c
			d.append(0)
	return result, d



def solve_repeater(p):
	#print "new case"
	n = StrToNum(p[0])
	cases = [s.strip() for s in p[1:]]
	res = []
	possible = True
	#print n, cases
	for s in cases:
		core, d = reduce_string(s)
		#print core, d
		res.append([core, d])

	#print res

	if len(set([i[0] for i in res])) != 1:
		return 'Fegla Won'
	
	len_d = len(res[0][1])
	sum_list = []

	for i in range(len_d):
		sum_list.append(0)
		temp = [j[1][i] for j in res]
		min_x = min(temp)
		max_x = max(temp)
		sum_x = 0
		
		for k in range(min_x, max_x):
			temp_sum = sum([abs(k - j[1][i]) for j in res])
			if sum_x:
				sum_x = min(sum_x, temp_sum)
				if temp_sum == sum_x:
					sum_list[i] = sum_x
			else:
				sum_x = temp_sum
				sum_list[i] = sum_x

	return sum(sum_list)

	#return '0'


	

###################################################################################################
					
problem = 'A'
s_input = 'large'
s_id = 'repeat'

nCase, inputList = parseInputData(problem, s_input, s_id)
result = []
rownum = 0

for i in range(nCase):
	n = StrToNum(inputList[rownum])	
	result.append("Case #%d: %s\n" %(i+1, solve_repeater(inputList[rownum : rownum + n + 1])))
	rownum += n + 1
	
writeOutput(result, problem, s_input, s_id)



		




		

