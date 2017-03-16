import sys

def check_argv():
	if len(sys.argv) < 3:
		print("USAGE: #python magic_trick.py INPUT_FILE OUTPUT_FILE")
		sys.exit()

def main():

	input_file = sys.argv[1]
	output_file = sys.argv[2]
	print input_file
	print output_file
	with open(input_file, "rb") as input, open(output_file,"w") as output:
		case_count = int(input.readline())
		for case_idx in range(1, case_count+1):
			ret = "case #"+str(case_idx)+": "
			check_one = int(input.readline())
			rows_one = []
			for i in range(4):
				rows_one.append(map(int, input.readline().split()))
			check_two = int(input.readline())
			rows_two = []
			for i in range(4):
				rows_two.append(map(int, input.readline().split()))
			answer_count = 0
			answer = 0
			for card in rows_one[check_one-1]:
				if card in rows_two[check_two-1]:
					answer_count += 1
					answer = card
			if answer_count == 1:
				ret += str(answer)+"\n"
			elif answer_count == 0:
				ret += "Volunteer cheated!\n"
			else:
				ret += "Bad magician!\n"
			output.write(ret)


"""
line =  "case #"+str(case_count)+": "+str(ret[0])+" "+str(ret[1])+"\n"
output.write(line)
"""

if __name__ == "__main__":
	main()