#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2016
Round 1C
Problem A
Senate Evacuation

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* I guess we just choose the party with the most senators at any step
	* but of course the final 2 must leave as a pair
	* and the 3rd last may have to leave alone to allow this
	* for 1000 senators, I guess it would take about 1000**2 steps to solve by a naive method?  that's efficient enough, so I guess we do that?
	* otherwise, we could sort by number of senators and keep the list updated as we move through it......
	* actually, it's only 26 items to check - not 1000... silly me - so it's more like 26 * 1000
	* are there other corner cases where we can slip over 50%, other than at the end? I don't think so

'''

################################################################################


def read_case(id, input):
	N = int(input.readline().rstrip())
	parties = [int(x) for x in input.readline().split()]
	assert(len(parties) == N)
	return parties

def solve_case(id, parties):
	
	total = sum(parties)
	
	plan = ''
	
	while total > 0:
		if total == 3:
			i = parties.index(max(parties))
			parties[i] -= 1
			plan += chr(i+ord('A'))
			total -= 1
		else:
			i = parties.index(max(parties))
			parties[i] -= 1
			plan += chr(i+ord('A'))
			total -= 1
			
			i = parties.index(max(parties))
			parties[i] -= 1
			plan += chr(i+ord('A'))
			total -= 1
		
		if total == 0:
			break
		
		plan += ' '
	
	return "Case #{}: {}\n".format(id, plan)


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
	#prepare()
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

