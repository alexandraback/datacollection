#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2015
Qualification Round
Problem B
Haircut

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* seems like a matter of implemented a simulation of the described process
	* will a direct implementation be too slow?
	* problem C seems too hard unless you are well-versed in geometry
		* you'd probably have to avoid floating point calculations to avoid potential for fp error
		* better to do problem B before looking in-depth at problem C
	* I might not succeed at the large dataset, so I'll try a simple algorithm for the small dataset first
	* actually, I'm thinking of an algorithm:
		* the idea is to home in... perhaps by binary search, on the correct position on the timeline
		* each barber has a repeating cycle, and we can instantly calculate their customers per minute or minutes per customer
		* actually, what if we work in floating point units...
			* calculate a total customers per minute value for all barbers together
			* calculate the minutes to serve N-1 customers from that
			* use that as a starting estimate...
	* maybe I should go straight for the large after all
	* maybe we should group the barbers by their cycle size? - would that amount to a big-O improvement though?
	* so it seems we'd be doing binary search on the minutes... do we even have a max value for that? -- 100,000 * 1,000,000,000 (worse case of 1 barber)
	* given a number of minutes, we can write a function to work out:
		* number of customers fully served so far
	* damn it... I can't waste more time thinking about it...
	* I'll do a binary search on the full 100,000,000,000,000 time space, right?
	* that will be umm...about 47 iterations... not bad - and we probably have to iterate over all barbers every iteration
	* I'm just a little unclear on how we get to the exact right position where customer N is just starting their cut
	* once we work out the time, we just iterate over barbers, filtered by those who are exactly finishing/starting

'''

################################################################################


def read_case(id, input):
	B, N = [int(n) for n in input.readline().split()]
	barbers = [int(n) for n in input.readline().split()]
	assert len(barbers) == B
	return (N, barbers)


def solve_case(id, case):
	N, barbers = case
	B = len(barbers)
	
	debug('{} {}\n{}\n'.format(B, N, barbers))
	
	def served_at(t):
		if t < 0:
			return 0
		served = B	# includes those just starting
		for barber_time in barbers:
			served += t // barber_time
		
		return served
	
	for t in range(20):
		served = served_at(t)
		debug('t: {}, served: {}\n'.format(t, served))
	
	
	def find_time(N):
		min = -1
		max = 100000 * 1000000000
		# range covered is min to max-1, inclusive
		last = 0
		while True:
			trial = (min + max) // 2
			assert trial != last
			served = served_at(trial)
			#debug('{}..{}..{}\n'.format(min, trial, max))
			#debug('N: {}, served: {}\n'.format(N, served))
			
			if served < N:
				min = trial
			else:
				max = trial
			
			if min + 1 == max:
				# max is the lowest time at which N or greater have been or are being served
				debug('time: {}, served: {}\n'.format(max, served))
				return max, served
			last = trial
	
	t, served = find_time(N)
	
	def find_barber(t, N, served):
		served = served_at(t-1)
		debug('previous: {}\n'.format(served))
		for barber_id, barber_time in enumerate(barbers):
			cut_progress = t % barber_time
			debug('{} {} {}\n'.format(barber_id, barber_time, cut_progress))
			if cut_progress == 0:
				served += 1
				if served == N:
					debug('id: {}\n'.format(barber_id))
					return barber_id
	
	barber_id = find_barber(t, N, served)
	
	return "Case #{}: {}\n".format(id, barber_id + 1)


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
	prepare()
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

