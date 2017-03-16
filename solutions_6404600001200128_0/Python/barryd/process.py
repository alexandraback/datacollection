#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2015
Qualification Round
Problem A
XXXXXXXX

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* at this stage I'm not even sure if a simple O(N) 2 or 3 passes over the samples is enough, or if it's more complex
	* the question is: does a calculated minimum rate then allow you to refine your minimum number of mushrooms consumed in a given interval, to a new value?
	* so you calculate min consumed per interval, and min rate (overall) from that, then recalculate min consumed based on that... and so on

'''

################################################################################


def read_case(id, input):
	N = int(input.readline())
	samples = [int(n) for n in input.readline().split()]
	assert len(samples) == N
	return samples

def solve_case(id, case):
	samples = case
	
	N = len(samples)
	
	total_eaten_1 = 0
	for i in range(1, N):
		eaten = max(0, samples[i-1] - samples[i])
		total_eaten_1 += eaten
	
	rate = 0
	for i in range(1, N):
		eaten = max(0, samples[i-1] - samples[i])
		time = 10
		newrate = eaten / time
		if newrate > rate:
			rate = newrate
	
	total_eaten_2 = 0
	for i in range(1, N):
		time = 10
		eaten = min(samples[i-1], rate * time)
		total_eaten_2 += eaten
	
	return "Case #{}: {} {}\n".format(id, total_eaten_1, int(total_eaten_2))


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
	#prepare()
	t1 = execution_timer()
	#report("Completed preparation in {:.6f} seconds.\n".format(t1 - t0))
	
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

