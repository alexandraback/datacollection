import sys
import time
import itertools #use combinations!
import random
import math

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



def solve1(R, C, N):
	if N <= R*C / 2:
		return 0
	to_seat = N - (R*C / 2)
	
	count = 0
	
	#points
	for i in xrange(R * C):
		if not to_seat:
			break
		if i%2:
			continue
		if (i == 0) or (i == C-1) or (i == R*C - 1) or (i == R*C - C):
			if R == 1 or C == 1:
				count += 1
			else:
				count += 2
			
			to_seat -= 1
		
	
	for i in xrange(R * C):
		if not to_seat:
			break
		if i%2:
			continue
		
		if (i == 0) or (i == C-1) or (i == R*C - 1) or (i == R*C - C):
			continue
		elif (i < C) or (i >= R*C - C) or (not (i % C)) or (not ((i+1) % C)):
			if R == 1 or C == 1:
				count += 2
			else:
				count += 3
			to_seat -= 1
		
		
	for i in xrange(R * C):
		if not to_seat:
			break
		if i%2:
			continue
		elif (i < C) or (i >= R*C - C) or (not (i % C)) or (not ((i+1) % C)):
			continue
		else:
			count += 4
			to_seat -= 1
		
	return count

def solve2(R, C, N):
	if (R*C) % 2 == 0:
		if N <= R*C / 2:
			return 0
		to_seat = N - (R*C / 2)
	else:
		if N <= R*C / 2 + 1:
			return 0
		to_seat = N - (R*C / 2 + 1)
	
	count = 0
	
	#points
	for i in xrange(R * C):
		if not to_seat:
			break
		if not i%2:
			continue
		if (i == 0) or (i == C-1) or (i == R*C - 1) or (i == R*C - C):
			if R == 1 or C == 1:
				count += 1
			else:
				count += 2
			to_seat -= 1
		
	
	for i in xrange(R * C):
		if not to_seat:
			break
		if not i%2:
			continue
		
		if (i == 0) or (i == C-1) or (i == R*C - 1) or (i == R*C - C):
			continue
		elif (i < C) or (i >= R*C - C) or (not (i % C)) or (not ((i+1) % C)):
			if R == 1 or C == 1:
				count += 2
			else:
				count += 3
			to_seat -= 1
		
	for i in xrange(R * C):
		if not to_seat:
			break
		if not i%2:
			continue
		if (i == 0) or (i == C-1) or (i == R*C - 1) or (i == R*C - C):
			continue
		elif (i < C) or (i >= R*C - C) or (not (i % C)) or (not ((i+1) % C)):
			continue
		else:
			count += 4
			to_seat -= 1
		
	return count
	
def calc_result(case):
	result = None
	R, C, N = list_to_int(case)
	print R,C,N
	
	if R == 1 and C == 1:
		return 0
	
	r1 = solve1(R, C, N)
	r2 = solve2(R, C, N)
	print r1, r2
	result = min(r1, r2)
	
	
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
		for case_index, case in iterate_cases_1lpc(filepath):
			
			print "case #%d: time:%.02f" % (case_index, time.time() - start_time)
			result = calc_result(case)
			
			#######################
			#### format output ####
			#######################
			f_out.write("Case #%d: %s\n" % (case_index, result))
				
if __name__ == '__main__':
	main(sys.argv[1])
