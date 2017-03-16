import os
import math

def solve(f_in):
	N = int(f_in.readline())

	strings = []
	for i in range(N):
		strings.append(f_in.readline()[:-1])
	master = ''

	test_string = strings[0]

	current_char = ''
	for i in test_string:
		if i != current_char:
			master += i
			current_char = i


	char_counts = []

	for string in strings:
		counts = []
		counter = 0
		base = string[0]
		curr_char = string[0]
		for i in string:
			if i != curr_char:
				counts.append(counter)
				counter = 1
				base += i
				curr_char = i
			else:
				counter += 1
		counts.append(counter)
		if base != master:
			return "Fegla Won"
		char_counts.append(counts)


	trans_char_counts = [list(x) for x in zip(*char_counts)]
	
	answer = 0
	for row in trans_char_counts:
		limit = max(row)
		x = 1
		temp = []
		while x <= limit:
			temp.append(sum([math.fabs(elem - x) for elem in row]))
			x += 1
		answer += min(temp)

	return int(answer)


	

if __name__ == "__main__":
	input_filename = 'A-small-attempt0.in'
	output_filename = 'R1B_A_small_output.txt'

	f_in = open(input_filename)
	counter = 0
	while os.path.isfile(output_filename):
		counter += 1
		output_filename = output_filename.split('.')[0] + str(counter) + '.txt'
	f_out = open(output_filename, 'a')

	test_cases = int(f_in.readline())
	
	for i in range(test_cases):
		ans = solve(f_in)
		f_out.write('Case #' + str(i + 1) +': ' + str(ans) + '\n')

	f_in.close()
	f_out.close()

	print 'Problem completed!'




