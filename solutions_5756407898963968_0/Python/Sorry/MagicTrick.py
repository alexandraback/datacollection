import sys
def main(argv):
	file_name = argv[0]
	f = open(file_name, 'r')
	number_tests = int(f.readline())
	number_reads = number_tests * 10
	for count in range(number_tests):
		first = int(f.readline())
		for count2 in range(first):
			first_line = f.readline()
		for count2 in range(4 - first):
			f.readline()
		second = int(f.readline())
		for count2 in range(second):
			second_line = f.readline()
		for count2 in range(4 - second):
			f.readline()
		first_line = first_line.split()
		second_line = second_line.split()
		shared = list(set(first_line).intersection(second_line))
		shared_len = len(shared)
		if shared_len == 1:
			print "Case #" + str(count+1) + ": " + shared[0]
		elif shared_len == 0:
			print "Case #" + str(count+1) + ": Volunteer cheated!"
		else:
			print "Case #" + str(count+1) + ": Bad magician!"

if __name__ == "__main__":
   main(sys.argv[1:])
