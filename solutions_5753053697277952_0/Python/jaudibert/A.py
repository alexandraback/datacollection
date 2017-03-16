

def find_max(ps):
	curr_max = 0
	for i in range(len(ps)):
		if ps[i] > ps[curr_max]:
			curr_max = i
	return curr_max

def make_plan(ps):
	abc = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
	plan = ""
	while sum(ps) != 0:
		i = find_max(ps)
		num = ps[i]
		ps[i] = ps[i] - 1
		j = find_max(ps)
		if ps[j] == num and sum(ps) != 2:
			ps[j] = ps[j] - 1
			plan += abc[i] + abc[j] + " "
		else:
			plan += abc[i] + " "
	return plan




def main():
	# take in input

	t = int(raw_input())

	solutions = []

	for i in range(t):
		n = int(raw_input())
		ps = map(int, raw_input().split())

		solutions.append("Case #" + str(i+1) + ": " + make_plan(ps))

	for solution in solutions:
		print solution


if __name__ == "__main__":
	main()