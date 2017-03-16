#-*- coding UTF-8 -*-
import string
letters = string.ascii_uppercase

def choose():
	array.sort(reverse=True)

	if array[0][0] > array[1][0]:
		for i in xrange(array[0][0] - array[1][0]):
			print letters[array[0][1]],
		array[0][0] = array[1][0]

	elif array[0][0] == 1 and array[1][0] == 1 and len(array)>2 and array[2][0] == 1:
		print letters[array[0][1]],
		array[0][0] -= 1

	else:
		print letters[array[0][1]] + letters[array[1][1]],
		array[0][0] -= 1
		array[1][0] -= 1

T = int(raw_input())
for t in xrange(1, T+1):
	print "Case #{}:".format(t),

	N = int(raw_input())
	array = map(int, raw_input().split())
	array = [[array[x], x] for x in xrange(N)]

	array.sort(reverse=True)


	while True:
		check = 0
		for i in array:
			check += i[0]
		if not check: break

		choose()
	print
