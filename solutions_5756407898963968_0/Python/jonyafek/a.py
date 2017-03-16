#!/usr/bin/python

import sys

in_f = open(sys.argv[1], "rt")

in_lines = in_f.readlines()

num_tests = int(in_lines[0])

in_lines = in_lines[1:]

out = ""

for i in xrange(num_tests):
	first_guess = int(in_lines[0])
	first_matrix = [ [0,0,0,0], [0,0,0,0], [0,0,0,0], [0,0,0,0]]
	for j in xrange(1,5):
		line = [int(n) for n in in_lines[j].split()]
		for k in xrange(4):
			first_matrix[j-1][k] = line[k]

	in_lines=in_lines[5:]

	second_guess = int(in_lines[0])
	second_matrix = [ [0,0,0,0], [0,0,0,0], [0,0,0,0], [0,0,0,0]]
	for j in xrange(1,5):
		line = [int(n) for n in in_lines[j].split()]
		for k in xrange(4):
			second_matrix[j-1][k] = line[k]

	in_lines=in_lines[5:]

	#print first_guess
	#print first_matrix


	#print second_guess
	#print second_matrix

	bad = False
	cheat = False
	answer = 0

	chosen_line_no_answers = True
	chosen_line_many_answers = False

	for k in xrange(4):
		for l in xrange(4):
			if second_matrix[second_guess-1][k] == first_matrix[first_guess-1][l]:
				chosen_line_no_answers = False
				if (answer != 0):
					chosen_line_many_answers = True
					continue

				answer = second_matrix[second_guess-1][k]
	
	if chosen_line_no_answers:
		cheat = True

	if chosen_line_many_answers:
		bad = True

	if (cheat):
		out += "Case #"+str(i+1)+": Volunteer cheated!\n"
		continue

	if (bad):
		out += "Case #"+str(i+1)+": Bad magician!\n"
		continue

	if (answer != 0):
		out += "Case #"+str(i+1)+": "+str(answer)+"\n"
		continue

print out
