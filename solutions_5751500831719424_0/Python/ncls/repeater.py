#!/usr/bin/env python

def get_char_list(s):
	char_list = [s[0]]
	for idx in range(1, len(s)):
		c_last = s[idx - 1]
		c = s[idx]
		if c != c_last:
			char_list.append(c)
	return char_list

def get_char_list_counts(s):
	char_list = [1]
	for idx in range(1, len(s)):
		c_last = s[idx - 1]
		c = s[idx]
		if c != c_last:
			char_list.append(1)
		else:
			char_list[-1] += 1
	return char_list

def is_solvable(s_list):
	char_list = get_char_list(s_list[0])
	for s in s_list[1:]:
		if char_list != get_char_list(s):
			return False
	return True

def get_str_dist(s1, s2):
	cl1 = get_char_list_counts(s1)
	cl2 = get_char_list_counts(s2)
	dist = 0
	for i in range(0, len(cl1)):
		dist += abs(cl1[i] - cl2[i])
	return dist

def get_min_dist(s_list):
	char_counts = [get_char_list_counts(s) for s in s_list]
	dist = 0
	for i in range(0, len(char_counts[0])):
		vals = [char_counts[j][i] for j in range(0, len(char_counts))]
		dists = []
		for val in vals:
			val_dist = sum([abs(val - v) for v in vals])
			dists.append(val_dist)
		dist += min(dists)
	return dist

def parse_input():
	t = input()
	test_cases = []
	for i in range(0, t):
		n = input()
		test_case_strs = []
		for j in range(0, n):
			test_case_strs.append(raw_input())
		test_cases.append(test_case_strs)
	return test_cases

def solve_test_case(test_case):
	if not is_solvable(test_case):
		return "Fegla Won"
	else:
		return get_min_dist(test_case)

def solve_all_test_cases(test_cases):
	for idx, test_case in enumerate(test_cases):
		print "Case #{}: {}".format(idx + 1, solve_test_case(test_case))

solve_all_test_cases(parse_input())