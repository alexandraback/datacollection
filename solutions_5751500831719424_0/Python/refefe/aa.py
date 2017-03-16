import sys
import math
import decimal

num_of_test_cases = int(sys.stdin.readline())
for k in xrange(1, num_of_test_cases + 1):
	N = int(sys.stdin.readline())
	strings = []
	for i in xrange(N):
		strings.append(sys.stdin.readline()[:-1])

	basic_rep = ""
	matrix = []
	lost = False
	for string in strings:
		br = string[0]
		cur_matrix = [0]
		for char in string:
			if br[-1] != char:
				br += char
				cur_matrix.append(1)
			else:
				cur_matrix[-1] += 1
		#print string
		#print br
		#print cur_matrix
		if basic_rep != "":
			if basic_rep != br:
				print "Case #{}: {}".format(k, "Fegla Won")
				lost = True
				break

		basic_rep = br
		matrix.append(cur_matrix)
	if lost:
		continue
	#print matrix
	y = 0
	for index in xrange(len(basic_rep)):
		min_moves = float('inf')
		for i in xrange(N):
			cur_moves = 0
			for j in xrange(N):
				cur_moves += abs(matrix[i][index] - matrix[j][index])
			if cur_moves < min_moves:
				min_moves = cur_moves

		y += min_moves


	print "Case #{}: {}".format(k, y)