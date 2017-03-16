from fractions import gcd

def lcm(a, b):
	return (a * b) // gcd(a, b)

class Barber:
	next_free = 0

	def __init__(self, idn, reload_time):
		self.idn = idn
		self.reload_time = reload_time

def solve():
	first_line = input()
	first_line = first_line.split()

	b = int(first_line[0])
	n = int(first_line[1])

	numbers = [int(x) for x in input().split()]

	if len(numbers) != b:
		print('ERROR 1')
		quit()

	repeat = 1
	for i in numbers:
		repeat = lcm(repeat, i)

	num_repeat = 0
	for i in numbers:
		num_repeat += repeat // i

	n -= 1
	n %= num_repeat

	barbers = [Barber(i, x) for i, x in enumerate(numbers, start=1)]

	time = 0
	while True:
		for b in barbers:
			if b.next_free <= time:
				if n == 0:
					return b.idn

				n -= 1
				b.next_free += b.reload_time

		time = float('inf')
		for b in barbers:
			time = min(time, b.next_free)


cases = int(input())
for i in range(1, cases + 1):
	print('Case #' + str(i) + ':', solve())