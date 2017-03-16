

def solve(resp1, board1, resp2, board2):
	options1 = set(board1[resp1-1])
	options2 = set(board2[resp2-1])
	total_options = options1 & options2
	if len(total_options) == 1:
		return total_options.pop()
	else:
		return "Bad magician!" if len(total_options) > 1 else "Volunteer cheated!"

def read_board(f):
	return [ [int(x) for x in f.readline().split()] for _ in range(4)]

def main():
	with open('input.txt','r') as f:
		problems = int(f.readline())
		answers = []
		for i in xrange(problems):
			resp1 = int(f.readline())
			board1 = read_board(f)
			resp2 = int(f.readline())
			board2 = read_board(f)
			answers.append("Case #%d: %s" % (i+1, solve(resp1, board1, resp2, board2)))
		with open('output.txt','w') as fout:
			fout.write('\n'.join(answers))




if __name__ == "__main__":
	main()