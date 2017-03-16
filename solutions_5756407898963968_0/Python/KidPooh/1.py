def main():
	f = open('1.in','r')
	outfile = open('1.out','w')
	num_of_cases = int(f.readline())
	for i in range(1,num_of_cases+1):
		first_answer = int(f.readline())	
		first_row1 = [int(a) for a in f.readline().replace("\n", "").split(" ")]
		first_row2 = [int(a) for a in f.readline().replace("\n", "").split(" ")]
		first_row3 = [int(a) for a in f.readline().replace("\n", "").split(" ")]
		first_row4 = [int(a) for a in f.readline().replace("\n", "").split(" ")]
		first_rows = [first_row1,first_row2,first_row3,first_row4]
		second_answer = int(f.readline())
		second_row1 = [int(a) for a in f.readline().replace("\n", "").split(" ")]
		second_row2 = [int(a) for a in f.readline().replace("\n", "").split(" ")]
		second_row3 = [int(a) for a in f.readline().replace("\n", "").split(" ")]
		second_row4 = [int(a) for a in f.readline().replace("\n", "").split(" ")]
		second_rows = [second_row1,second_row2,second_row3,second_row4]
		first_selected_row = first_rows[first_answer-1]
		second_selected_row = second_rows[second_answer-1]
		same_cards = set(first_selected_row) & set(second_selected_row)
		if(len(same_cards) == 0):
			outfile.write("Case #" + str(i) + ": " + "Volunteer cheated!\n")
		if(len(same_cards) > 1):
			outfile.write("Case #" + str(i) + ": " + "Bad magician!\n")
		if(len(same_cards) == 1):
			outfile.write("Case #" + str(i) + ": " + str(same_cards.pop()) + "\n")
	f.close()
	outfile.close()
if __name__ == "__main__":
	main()
