#!/usr/bin/env python

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())


	for T in xrange(1,total_T+1):
		R, C, N = map(int, f.readline().rstrip('\n').split())

		cells = {}
		for r in xrange(R):
			for c in xrange(C):
				cells.setdefault((r, c), APT(r, c, R, C, cells))


		# cells[(0, 0)].used = True


		# print cells
		total = sum(1 for x in cells.itervalues() if x.used)
		while total > N:
			max_unhappy = reduce(lambda x,y: x if x.unhappy()>y.unhappy() else y, filter(lambda x: x.used, cells.itervalues())).unhappy()

			# print max_unhappy
			for r in xrange(R):
				for c in xrange(C):
					if cells[(r, c)].used and cells[(r, c)].unhappy() == max_unhappy and total > N:
						cells[(r, c)].used = False
						# print cells
						total -= 1
						# return

		# print cells, '\n\n\n\n'
		# print sum(x.unhappy() for x in cells.itervalues() if x.used)
		min_unhappy = sum(x.unhappy() for x in cells.itervalues() if x.used)/2
		# print  '\n\n\n\n'



		print 'Case #{}: {}'.format(T, min_unhappy)


class APT():
	def __init__(self, r, c, R, C, cells):
		self.r = r
		self.c = c
		self.R = R
		self.C = C
		self.cells = cells
		self.used = True

	def left(self):
		if self.r == 0:
			return None
		return self.cells[(self.r-1, self.c)]
	def right(self):
		if self.r == self.R - 1:
			return None
		return self.cells[(self.r+1, self.c)]
	def up(self):
		if self.c == 0:
			return None
		return self.cells[(self.r, self.c-1)]
	def down(self):
		if self.c == self.C - 1:
			return None
		return self.cells[(self.r, self.c+1)]

	def unhappy(self):
		# if used, what is the unhappy count
		c = 0
		if self.left() and self.left().used:
			c += 1
		if self.right() and self.right().used:
			c += 1
		if self.up() and self.up().used:
			c += 1
		if self.down() and self.down().used:
			c += 1
		return c

	def __repr__(self):
		return 'APT({}, {}, used={}, unhappy={})'.format(self.r, self.c, self.used, self.unhappy())



if __name__ == '__main__':
	main()