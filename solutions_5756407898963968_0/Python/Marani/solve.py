import time

file_in = file('test.in', 'r')
file_out = file('test.out', 'w')

def main():
	n_case = int(file_in.readline())
	for case in range(1, n_case + 1):
		solveCase(case)

def solveCase(case_number):
	#in
	n_row = 4
	n_col = 4
	r_1 = int(file_in.readline())
	for i in range(n_row):
		col_str = file_in.readline()
		if i == r_1 - 1:
			set_1 = set(map(int, col_str.split()))

	r_2 = int(file_in.readline())
	for i in range(n_row):
		col_str = file_in.readline()
		if i == r_2 - 1:
			set_2 = set(map(int, col_str.split()))
	#main
	print set_1, set_2
	intersect_len = len(list(set_1 & set_2))

	if intersect_len == 0:
		result = "Volunteer cheated!"
	elif intersect_len > 1:
		result = "Bad magician!"
	else:
		result = repr(list(set_1 & set_2)[0])

	#out
	file_out.write("Case #" + repr(case_number) + ": " + result + "\n")


if __name__ == '__main__':
	startTime = time.clock()
	main()
	print (time.clock() - startTime)