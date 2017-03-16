
def process(i, o):
	T = int(i.readline())
	for case_num in range(1, T + 1):
		choice1 = int(i.readline())
		grid1 = [map(int, i.readline().split()) for _ in range(4)]
		choice2 = int(i.readline())
		grid2 = [map(int, i.readline().split()) for _ in range(4)]
		ans = solve(grid1, grid2, choice1, choice2)
		o.write('Case #{}: {}\n'.format(case_num, ans))
		print 'Case #{}/{}: {}'.format(case_num, T, ans)
		print

def solve(grid1, grid2, choice1, choice2):
	ans_set = set(i for i in range(1, 16 + 1))
	for choice, grid in [[choice1, grid1], [choice2, grid2]]:
		new_set = set(card for card in grid[choice - 1])
		ans_set = ans_set.intersection(new_set)

	if len(ans_set) > 1:
		return 'Bad magician!'
	elif len(ans_set) == 0:
		return 'Volunteer cheated!'
	else:
		return ans_set.pop()


def main():
	cyclename = 'A-small-0'
	with open('source\\{}.in'.format(cyclename), 'rb') as i:
		with open('source\\{}.out'.format(cyclename), 'wb') as o:
			process(i, o)
		

if __name__ == '__main__':
	main()
