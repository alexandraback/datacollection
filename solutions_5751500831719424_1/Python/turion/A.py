#! /usr/bin/python
# -*- coding: utf-8 -*-


import codejammer # https://bitbucket.org/turion/codejammer

def normal(string):
	last = ""
	normalstring = ""
	counter = []
	for x in string:
		if x != last:
			normalstring += x
			last = x
			counter.append(0)
		else:
			counter[-1] += 1
	return (normalstring, counter)

def multi(mult):
	mult = sorted(mult)
	#input(mult)
	median = mult[int((len(mult)-1)/2)]
	#input(median)
	return sum(abs(median-i) for i in mult)

def solve_case_small(case):
	#input(case)
	if case[0] != 2:
		return None
	strings = [normal(string[0]) for string in case[1:]]
	#input(strings)
	if not all(n[0] == strings[0][0] for n in strings):
		return "Fegla Won"
	return sum(abs(x-y) for x,y in zip(strings[0][1], strings[1][1]))



def solve_case(case):
	#input(case)
	strings = [normal(string[0]) for string in case[1:]]
	#input(strings)
	if not all(n[0] == strings[0][0] for n in strings):
		return "Fegla Won"
	return sum(multi(mults) for mults in zip(*(string[1] for string in strings)))


test_in = """5
2
mmaw
maw
2
gcj
cj
3
aaabbb
ab
aabb
2
abc
abc
3
aabc
abbc
abcc"""

test_solution = """Case #1: 1
Case #2: Fegla Won
Case #3: 4
Case #4: 0
Case #5: 3"""



codejammer.set_level(codejammer.DEBUG)
#codejammer.test_jam(test_in, test_solution, solve_case, handler="numbered", interact=True)
codejammer.jam("A", solve_case, handler="numbered")
