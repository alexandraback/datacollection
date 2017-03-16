import sys

def main():
	num_test_cases = int(sys.stdin.readline())
	for i in range(num_test_cases):
		num_senators = int(str(sys.stdin.readline().strip()))
		input_ = str(sys.stdin.readline().strip())
		print("Case #{}: {}".format(i + 1, function(input_)))

def function(string):
	num_senators = list(map(int, string.split(" ")))  # [3, 2, 1]
	with_parties = list(zip(num_senators, [chr(i + ord('A')) for i in range(len(num_senators))]))
	with_parties_sorted = sorted(with_parties, key=lambda party: -party[0])
#	print(with_parties_sorted)
	print_list = []
	while len(with_parties_sorted) > 1:
		evac_pair = ''
		num_iter = 2
		num_people_left = sum(party[0] for party in with_parties_sorted)
		if num_people_left == 3:
			num_iter = 1
		for i in range(num_iter):
			while len(with_parties_sorted) > 0 and with_parties_sorted[0][0] < 1:
				with_parties_sorted.pop(0)
			if with_parties_sorted:
				(num_people, party) = with_parties_sorted[0]
				with_parties_sorted[0] = (num_people - 1, party)
				evac_pair += with_parties_sorted[0][1]
				with_parties_sorted.sort(key=lambda party: -party[0])
		if evac_pair != '': print_list.append(evac_pair)
	# if len(with_parties_sorted) == 1:
	# 	print_list.append(with_parties_sorted[0][1])
	# else:
	# 	print_list.pop(-1)

	return " ".join(print_list)

if __name__ == '__main__':
	main()