'''
Created on Mar 11, 2014

@author: John Cornwell
'''
import operator,math,string,itertools,fractions,heapq,collections,re,array,bisect,random
from fractions import gcd
def lcm(a, b):
	return a * b / gcd(a, b)


# Called before solving any functions
def init(i_num, fc_in):
	return
	


# Parse next set of arguments
def parse_next(fc_in):
	c1 = int(fc_in.readline()[:-1])
	for i in range(4):
		spos = set(map(int, fc_in.readline().split()))
		if i == c1 - 1:
			s1 = spos
	c2 = int(fc_in.readline()[:-1])
	for i in range(4):
		spos = set(map(int, fc_in.readline().split()))
		if i == c2 - 1:
			s2 = spos
	return s1, s2



# Solve individual instance
def solve(s1, s2):
	pos = s1 & s2
	if len(pos) == 0:
		return 'Volunteer cheated!'
	if len(pos) > 1:
		return 'Bad magician!'
	return pos.pop()

	



def _run_main():
	# Config
	s_let = 'A'
	s_run = 1
	
	if s_run == 0:
		fc_in = open('infile.in', 'r')
	elif s_run == 1:
		fc_in = open('Z:\Users\John Cornwell\Desktop\%s-small-attempt0.in' % s_let, 'r')
	else:
		fc_in = open('C:\Users\John Cornwell\Desktop\%s-large-practice.in' % s_let, 'r')
	fc_out = open('out.txt', 'w')
	
	i_num = int(fc_in.readline())
	init(i_num, fc_in)
	
	# Pare and solve test cases
	for i in range(1, i_num+1):
		args = parse_next(fc_in)
		ret = solve(*args)
		s_line = 'Case #%i: %s' % (i, str(ret))
		print s_line
		fc_out.write(s_line + '\n')
		
		
if __name__ == '__main__':
	_run_main()