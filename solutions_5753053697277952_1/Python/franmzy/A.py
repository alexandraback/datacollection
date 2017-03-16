# -*- coding: utf-8 -*-
######################################################
##                                                  ##
##  Fran Muñoz                                      ##
##  email: fran.mzy@gmail.com                       ##
##  UVA user: franmzy                               ##
##  Linkedin: https://www.linkedin.com/in/franmzy   ##
##                                                  ##
######################################################

n_cases = int(input())

for i_case in range(n_cases):

	N = int(input())
	politics = list(map(int, input().split()))

	total = sum(politics)

	polSort = sorted([(politics[i], i) for i in range(len(politics))], reverse=True)

	queue = []

	while polSort[0][0] >= polSort[1][0] and polSort[0][0] > 0:
		# if total == 3:
		# 	queue.append(polSort[0])
		# 	total -= 1
		# 	polSort[0] = (polSort[0][0]-1, polSort[0][1])
		# else:
		for j in range(max(polSort[1][0], 1), polSort[0][0]+1):
			queue.append(polSort[0])
		polSort[0] = (polSort[1][0]-1, polSort[0][1]) 

		polSort = sorted(polSort, reverse=True)

	print('Case #{0}:'.format(i_case+1), end=" ")

	queue.reverse()
	while queue:
		print(chr(ord('A') + queue.pop()[1]), end="")
		total -= 1
		if queue and total != 2:
			print(chr(ord('A') + queue.pop()[1]), end="")
			total -= 1
		if queue:
			print(" ", end = " ")
	print()