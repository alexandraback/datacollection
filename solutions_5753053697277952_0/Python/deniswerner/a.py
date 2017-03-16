# -*- coding: utf-8 -*-



def description():
	print """
	Input

	The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of two lines. The first line contains a single integer N, the number of parties. The second line contains N integers, P1, P2, ..., PN, where Pi represents the number of senators of the party named after the i-th letter of the alphabet.
	Output

	For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the evacuation plan. The plan must be a space-separated list of instructions, in the order in which they are to be carried out, where each instruction is either one or two characters, representing the parties of the senators to evacuate in each step.

	It is guaranteed that at least one valid evacuation plan will exist. If multiple evacuation plans are valid, you may output any of them.
	Limits

	1 ≤ T ≤ 50.
	No party will have an absolute majority before the start of the evacuation.
	1 ≤ Pi ≤ 1000, for all i.
	Small dataset

	2 ≤ N ≤ 3.
	sum of all Pi ≤ 9.
	Large dataset

	2 ≤ N ≤ 26.
	sum of all Pi ≤ 1000.
"""


def solve(x):
	sen_list = x.split(" ")
	sen_list = [int(y) for y in sen_list]
	solution = ""

	while sum(sen_list) > 0:
		evacs = 2

		# even out
		max_s = max(sen_list)

		count = 0
		for si in range(len(sen_list)):
			if sen_list[si] == max_s:
				count += 1
		if (count % 2) == 1:
			print "take one",sen_list
			evacs = 1			
		else:
			print "take two",sen_list
			evacs = 2
		for si in range(len(sen_list)):
			if evacs == 0:
				break
			if sen_list[si] == max_s:
				sen_list[si] -= 1
				solution += ALPHABET[si]
				evacs -= 1
		


		if sum(sen_list) > 0:
			solution += " "


	return solution


ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

FILENAME = "A-large"
FILENAME = "A-small-attempt0"
#FILENAME = "A-test"

with open(FILENAME + ".in","r") as f:
	content = f.read().splitlines()

no_of_cases = int(content[0])


outputs = []
for ci in range(1,len(content),2):
	c = content[ci]
	c2 = content[ci+1]
	print c,"#", c2
	result = solve(c2)
	print result, c
	outputs.append(result)

with open("" + FILENAME +".out","w") as f:
	for o in range(len(outputs)):
		f.write("Case #"+ str(o+1) + ": " + outputs[o] + "\n")
