import sys
import itertools

input_file = open(sys.argv[1])
output_file = open(sys.argv[1] + ".out", "w")

T = int(input_file.readline().strip())
for t in range(1, T + 1):
	R, C, N = tuple(map(int, input_file.readline().strip().split(" ")))

	min_unhappiness = float("inf")

	for occupied in itertools.combinations(range(R * C), N):
		loud_walls = set()
		for x in occupied:
			if x - 1 in occupied and x % C != 0:
				loud_walls.add(frozenset((x, x - 1)))

			if x + 1 in occupied and x % C != C - 1:
				loud_walls.add(frozenset((x, x + 1)))

			if x - C in occupied:
				loud_walls.add(frozenset((x, x - C)))

			if x + C in occupied:
				loud_walls.add(frozenset((x, x + C)))

		if len(loud_walls) < min_unhappiness:
			min_unhappiness = len(loud_walls)
			# print(occupied, list(map(list, loud_walls)))

	# print(min_unhappiness)
	output_file.write("Case #{0}: {1}\n".format(t, min_unhappiness))
