import sys

def find_sum_of_subs(mushrooms):
	sum = 0
	i = 0
	while(i < len(mushrooms)):
		if(i > 0):
			diff = mushrooms[i-1] - mushrooms[i]
			if(diff > 0):
				sum += diff
		i += 1
	return sum

def find_max_diff(mushrooms):
	max_diff = 0
	i = 0
	while(i < len(mushrooms)):
		if(i > 0):
			diff = mushrooms[i-1] - mushrooms[i]
			if(diff > max_diff):
				max_diff = diff
		i += 1
	return max_diff

def sum_eat_const(mushrooms, rate):
	sum = 0
	i = 0
	while(i < (len(mushrooms) - 1)):
		if(mushrooms[i] > rate):
			sum += rate
		else:
			sum += mushrooms[i]
		i += 1
	return sum
	
def solve(in_file, out_file, case):
	out_file.write('Case #' + str(case + 1) + ': ')
	
	line = in_file.readline().replace('\n', '')
	num_mushrooms = int(line)
	mushrooms = in_file.readline().replace('\n', '').split(' ')
	i = 0
	while(i < len(mushrooms)):
		mushrooms[i] = int(mushrooms[i])
		i += 1
	
	out_file.write(str(find_sum_of_subs(mushrooms)) + ' ')
	out_file.write(str(sum_eat_const(mushrooms, find_max_diff(mushrooms))))
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