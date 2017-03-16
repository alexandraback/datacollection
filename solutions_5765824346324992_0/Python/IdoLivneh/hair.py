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

#def solve(B, N, Ms):
#
#	min_M = min(Ms)
#	
#	times = []
#	for b in xrange(B):
#		t = 0
#		while t < min_M * N:
#			times.append([t, b + 1])
#			t += Ms[b]
#	
#	times.sort()
#	print times[N-1]
#	return times[N-1][1]

#def comm_list_gcd(lst):
#	import fractions.gcd as gcd
#	g = gcd(lst[0], lst[1])
#	for i in xrange(len(lst)):
#		if i <= 1:
#			continue
#		if not g == gcd(g, lst[i]):
#			return False

def solve(B, N, Ms):
	s = 0
	for i in xrange(B):
		s += 1.0/Ms[i]
	t_init = int(math.floor(1.0 * (N - B) / s))
	print "t_init: %d" % t_init
	last_c = 0
	
	for delta in xrange(8*B + 2):
		t = t_init - 4*B - 1 + delta
		if t < 0:
			continue
		c = 0
		for b in xrange(B):
			c += 1 + t / Ms[b]
		print "t:%d, c:%d" % (t, c)
		if c >= N:
			
			bla = N - last_c
			print "\tN:%d, last_c:%d, bla:%d" % (N, last_c, bla)
			count = 0
			for b in xrange(B):
				if not t % Ms[b]:
					count += 1
					if count == bla:
						return b + 1
		last_c = c
	
	return None
	
def calc_result(case):
	result = None
	print case
	
	B, N = list_to_int(case[0])
	Ms = list_to_int(case[1])
	
	print B, N, Ms
	
	result = solve(B, N, Ms)
	
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
		for case_index, case in iterate_cases_nlpc(filepath, 2):
			
			print "case #%d: time:%.02f" % (case_index, time.time() - start_time)
			result = calc_result(case)
			
			#######################
			#### format output ####
			#######################
			f_out.write("Case #%d: %s\n" % (case_index, result))
				
if __name__ == '__main__':
	main(sys.argv[1])
