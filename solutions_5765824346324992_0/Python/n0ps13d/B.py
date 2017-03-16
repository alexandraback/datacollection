from __future__ import division
from fractions import gcd
from heapq import *

def lcm(a, b):
	return a*b//gcd(a, b)

fin = open('B-small-attempt1.in', 'r')
fout = open('B.out', 'w')

cases = int(fin.readline().rstrip('\n'))
# print cases

# print lcm(5, 10)

for case in xrange(1, cases+1):
	answer = 'Case #' + str(case) + ': '
	barbers, position = [int(i) for i in fin.readline().rstrip('\n').split()]
	delays = [int(i) for i in fin.readline().rstrip('\n').split()]

	common = 1
	for delay in delays:
		common = lcm(common, delay)

	# print common

	replay = 0
	for delay in delays:
		replay += common//delay

	# print replay

	position = position % replay
	if position == 0:
		position = replay

	# print barbers, position
	# print delays

	line = []
	for barber, delay in enumerate(delays):
		heappush(line, (0+barber/100000, barber))

	# print line

	customer = 1
	while customer < position:
		# print customer, line
		time, barber = [int(i) for i in heappop(line)]
		# print time, barber
		heappush(line, (time+delays[barber]+barber/100000, barber))
		customer += 1
		
	# print customer, line
	# Haircut time!!!
	time, barber = heappop(line)
	answer += str(barber+1)
	print answer
	fout.write(answer + '\n')


fin.close()
fout.close()