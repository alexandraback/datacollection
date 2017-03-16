import sys

# Find how many barbers before they return to all open
def find_cycle_length(barber_times):
	waits = barber_times[:]
	cycle_len = len(barber_times)
	done = False
	while(not done):
		if not 0 in waits:
			min_wait = min(waits)
			i = 0
			while(i < len(waits)):
				waits[i] -= min_wait
				i += 1
		if(all(wait == 0 for wait in waits)):
			done = True
			break
		i = 0
		while(i < len(waits)):
			if(waits[i] == 0):
				waits[i] = barber_times[i]
				break
			i += 1
		cycle_len += 1
	return cycle_len

def find_barber(barber_times, place_in_line):
	next_in_line = 0
	last_taken_barber = len(barber_times)
	waits = barber_times[:]
	i = 0
	while(i < len(waits)):
		waits[i] = 0
		i += 1
	while(next_in_line <= place_in_line):
		
		#print 'Processing ' + str(next_in_line) + ' person in line, you are ' + str(place_in_line)
		
		if not 0 in waits:
			min_wait = min(waits)
			
			#print 'Waiting: ' + str(min_wait) + ' min on ' + str(waits)
			
			i = 0
			while(i < len(waits)):
				waits[i] -= min_wait
				i += 1
			
			#print '=> ' + str(waits)
			
		i = 0
		while(i < len(waits)):
			if(waits[i] == 0):
				break
			i += 1
		last_taken_barber = i + 1
		waits[i] = barber_times[i]
		
		#print 'Barber#' + str(last_taken_barber) + ' is free, waits: ' + str(waits)
		
		next_in_line += 1
	return last_taken_barber

def solve(in_file, out_file, case):
	out_file.write('Case #' + str(case + 1) + ': ')
	
	num_barbers, place_in_line = in_file.readline().replace('\n', '').split(' ')
	barber_times = in_file.readline().replace('\n', '').split(' ')
	num_barbers = int(num_barbers)
	place_in_line = int(place_in_line) - 1
	i = 0
	while(i < len(barber_times)):
		barber_times[i] = int(barber_times[i])
		i += 1
	
	cycle_len = find_cycle_length(barber_times)
	if(place_in_line > cycle_len):
		place_in_line %= cycle_len
	
	#print 'cycle_len = ' + str(cycle_len)
	#print barber_times
	
	answer = find_barber(barber_times, place_in_line)
	#print answer
	
	out_file.write(str(answer))
	out_file.write('\n')

if len(sys.argv) != 2:
	print 'Please provide one parameter with the name of the input file location relative to this file.'
else:
	in_file = open(str(sys.argv[1]), 'r')
	out_file = open(str(sys.argv[1]).replace('.in', '.out'), 'w')
	cases = int(in_file.readline())
	case = 0
	while (case < cases):
		solve(in_file, out_file, case)
		case += 1
	in_file.close()
	out_file.close()