import sys
import time
import itertools #use combinations!
import random
import math

DELTA = 1e-4

def iterate_cases_1lpc(filepath):	#1lpc = 1 line per case
	with file(filepath, 'rb') as f_in:
		for line_index, line in enumerate(f_in):
			if line_index == 0: #T
				continue
			yield line_index, line.strip().split(' ')

def iterate_cases_nlpc(filepath, n):	#nlpc = n line per case
	with file(filepath, 'rb') as f_in:
		case_counter = 1
		case = []
		for line_index, line in enumerate(f_in):
			if line_index == 0: #T
				continue
			case.append(line.strip().split(' '))
			if not line_index % n:
				yield case_counter, case
				case_counter += 1
				case = []

def iterate_cases_glpc(filepath):		#glpc - given lines per case
	with file(filepath, 'rb') as f_in:
		case_counter = 0
		new_case = True
		for line_index, line in enumerate(f_in):
			if line_index == 0: #T
				continue
			if new_case:
				new_case = False
				case_counter += 1
				case = []
				assert len(line.strip().split(' ')) == 1
				lines_left = int(line.strip())
				if not lines_left:
					new_case = True
					yield case_counter, case
				continue
			if lines_left:
				lines_left -= 1
				case.append(line.strip().split(' '))
			if not lines_left:
				new_case = True
				yield case_counter, case
			
def part_of_list_to_int(array, flags):
	assert len(array) == len(flags)
	output = []
	for index, elem in enumerate(array):
		if flags[index]:
			output.append(int(elem))
		else:
			output.append(elem)
	return output

def list_to_int(array):
	return part_of_list_to_int(array, [True] * len(array))

def part_of_list_to_float(array, flags):
	assert len(array) == len(flags)
	output = []
	for index, elem in enumerate(array):
		if flags[index]:
			output.append(float(elem))
		else:
			output.append(elem)
	return output

def list_to_float(array):
	return part_of_list_to_float(array, [True] * len(array))

def get_max_array_on_index(array, index):
	elem_len = len(array[0])
	assert index < elem_len
	for elem in array:
		assert elem_len == len(elem)
	max_sub = array[0][index]
	max_elem = array[0]
	for elem in array:
		if elem[index] > max_sub:
			max_sub = elem[index]
			max_elem = elem
	return max_elem

def list_index_in_sorted_with_position(a_list, value, pos):
	list_len = len(a_list)
	if list_len == 1:
		if a_list[0] == value:
			return pos
		return -1
	if a_list[list_len/2] > value:
		return list_index_in_sorted_with_position(a_list[:(list_len/2)], value, pos)
	else:
		return list_index_in_sorted_with_position(a_list[(list_len/2):], value, pos + (list_len/2))
	
def list_index_in_sorted_list(a_list, value):
	return list_index_in_sorted_with_position(a_list, value, 0)

def copy_list(list):
	res = []
	for elem in list:
		res.append(elem)
	return res	

############################################################
#### add solution here 									####
#### don't forget to change data from str to int/float  ####
############################################################

def solve(Ts):

	if len(Ts) <= 2:
		return [0] * len(Ts)
		
	res = []
	
	for i in xrange(len(Ts)):
		mins = []
		for j in xrange(len(Ts)):
			if j == i:
				continue
			
			x1 = Ts[i][0]
			y1 = Ts[i][1]
			x2 = Ts[j][0]
			y2 = Ts[j][1]
			
			if x2 == x1:
				count_right = 0
				count_left = 0
				for k in xrange(len(Ts)):
					if k == i or k == j:
						continue
					x = Ts[k][0]
					if x > x1:
						count_right += 1
					if x < x1:
						count_left += 1
				mins.append(min(count_right, count_left))
					
			
			else:  # vertical
				a = (1.0 * y2 - y1) / (x2 - x1)
				b = (1.0 * y1 * x2 - x1 * y2) / (x2 - x1)
				
				if not abs(y1 - a * x1 - b) < DELTA:
					print 'bad: (%d,%d),(%d,%d), a:%.2f, b:%.2f' % (x1, y1, x2, y2, a, b)
					#print abs(y1 - a * x1 - b) < DELTA
					#return
				if not abs(y2 - a * x2 - b) < DELTA:
					print 'bad'
					
				count_above = 0
				count_below = 0
				for k in xrange(len(Ts)):
					if k == i or k == j:
						continue
					x = Ts[k][0]
					y = Ts[k][1]
					if y > (a * x + b + DELTA):
						count_above += 1
					if y < (a * x + b - DELTA):
						count_below += 1
			
				mins.append(min(count_above, count_below))
		
		res.append(min(mins))
				
	return res
	
def calc_result(case):
	result = None
	#print case
	
	Ts = []
	for tree in case:
		Ts.append(list_to_float(tree))
	#print Ts
	result = solve(Ts)
	print result
	
	return result

def main(filepath):
	start_time = time.time()
	with file('output.txt', 'wb') as f_out:
		
		######################################
		#### select input iteration type: ####
		####	- iterate_cases_1lpc	  ####
		####	- iterate_cases_nlpc +n	  ####
		####	- iterate_cases_glpc	  ####
		######################################
		for case_index, case in iterate_cases_glpc(filepath):
			
			print "case #%d: time:%.02f" % (case_index, time.time() - start_time)
			result = calc_result(case)
			
			#######################
			#### format output ####
			#######################
			f_out.write("Case #%d:\n" % case_index)
			for r in result:
				f_out.write("%d\n" % r)
				
if __name__ == '__main__':
	main(sys.argv[1])
