#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2014
Qualification Round
Problem A
Magic Trick

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:


'''

################################################################################


def read_case(id, input):
	q1 = int(input.readline())
	g1 = dict()
	for i in range(1,5):
		g1[i] = [int(x) for x in input.readline().split()]
	
	q2 = int(input.readline())
	g2 = dict()
	for i in range(1,5):
		g2[i] = [int(x) for x in input.readline().split()]
	
	case = q1, g1, q2, g2
	
	return case

def solve_case(id, case):
	q1, g1, q2, g2 = case
	
	set1 = set(g1[q1])
	set2 = set(g2[q2])
	
	options = set.intersection(set1, set2)
	noptions = len(options)
	
	if noptions == 0:
		solution = 'Volunteer cheated!'
	elif noptions == 1:
		solution = next(iter(options))
	else:
		solution = 'Bad magician!'
	
	return "Case #{}: {}\n".format(id, solution)


def prepare():
	def prepare_data():
		return None
	
	global prepared_data
	prepared_data = prepare_cached(prepare_data, 'prepared_data.cached')


################################################################################


from sys import stdin, stdout, stderr
import time
import math
import pickle
import io

execution_timer = time.time
#execution_timer = time.clock
debugging = 1


################################################################################


def debug(message):
	if debugging:
		stderr.write(message() if hasattr(message, '__call__') else message)

def report(message):
	stderr.write(message)

def prepare_cached(prepare_data, pickle_path='data.pickle'):
	try:
		data = pickle.load(io.open(pickle_path, 'rb'))
		report("Loaded {}.\n".format(pickle_path))
	except IOError:
		data = prepare_data()
		report("Prepared {}.\n".format(pickle_path))
		pickle.dump(data, io.open(pickle_path, 'wb'))
	return data

def main():
	t0 = execution_timer()
	# prepare()
	t1 = execution_timer()
	report("Completed preparation in {:.6f} seconds.\n".format(t1 - t0))
	
	T = int(stdin.readline())
	for case_id in range(1,T+1):
		report("Processing test case {} of {} (output {}). {:.0f} seconds elapsed.".format(case_id, T, case_id-1, execution_timer() - t1))
		report("\n" if debugging else "\r")
		stderr.flush()
		stdout.write(solve_case(case_id, read_case(case_id, stdin)))
		stdout.flush()
	
	t2 = execution_timer()
	report("Processed {} test cases in {:.6f} seconds.                           \n".format(T, t2 - t1))
	report("Total time: {:.6f} seconds.\n".format(t2 - t0))

if __name__ == '__main__':
	main()

