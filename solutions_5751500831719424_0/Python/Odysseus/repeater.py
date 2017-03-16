#!/usr/bin/python


import sys
import fileinput
import numpy as np

def minimum_literal(word):
	last_c=''
	min_word=''
	cnt=0
	repetitions=list()
	for i in xrange(0, len(word)):
		if last_c != word[i]:
			min_word+=word[i]
			last_c=word[i]
			if cnt !=0:
				repetitions.append(cnt)
			cnt=1
		else:
			cnt+=1
	if cnt !=0:
		repetitions.append(cnt)
	return min_word,repetitions

def is_possible(literals):
	min_literals=set()
	cnt=0
	repetitions=list()
	for i in literals:
		min_word, rep=minimum_literal(i)
		repetitions.append(rep)
		min_literals.add(min_word)
		cnt+=1
		if(len(min_literals) != 1):
			return False, '', list()
	return True, min_word, repetitions

cur_case=0
test_cases=1
subcase=0
subcases=0

for line in fileinput.input():
	if(cur_case > test_cases):
#		print 'error'
		break;
	if(cur_case == 0):
		test_cases=int(line.rstrip());
		cur_case+=1;
		continue
	if(subcases==0):
		subcases=int(line.rstrip());
		literals=list()
	else:
		if(subcase < subcases-1):
			literals.append(line.rstrip())
			subcase+=1;
		else:
			literals.append(line.rstrip())
			ret, min_word, repetitions=is_possible(literals);
			if(ret == False):
				print 'Case #'+str(cur_case)+': Fegla Won'
			else:
				medians=list()
				for i in xrange(0, len(repetitions[0])):
					r=list()
					for j in xrange(0, len(repetitions)):
						r.append(repetitions[j][i])
					r=np.array(r)
					median=np.median(r)
					medians.append(int(median))
				moves=0;
				for i in xrange(0, len(repetitions[0])):
					for j in xrange(0, len(repetitions)):
						moves+=abs(medians[i]-repetitions[j][i])
				print 'Case #'+str(cur_case)+': ' + str(moves)
			subcases=0
			subcase=0
			cur_case+=1;
