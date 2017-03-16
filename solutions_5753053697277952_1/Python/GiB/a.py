# -*- coding: UTF-8 -*-
from queue import PriorityQueue

def letter(n):
	return str(chr(n+ord('A')))

def peek(q):
	x = q.get()
	q.put(x)
	return x

def resalgo(n):
	return n
	
def algo(inp):
	n = inp.int
	people = PriorityQueue()
	res = []
	for i in range(n):
		x = inp.int
		people.put((-x, x, i))
	cont = True
	while cont:
		(_,a,b) = people.get()
		(_,i,las) = peek(people)
		print((a,b,i,las))
		if people.qsize() < 2:
			for j in range(a):
				res.append(letter(b)+letter(las))
			cont = False
		else:
			for j in range(a-i+1):
				res.append(letter(b))
			if i>1:
				people.put((1-i,i-1,b))
	return ' '.join(res)

########################
# Miscaleanous
########################

from fractions import Fraction

def cmp_f(x, y):
  """Returns True iff y is within relative or absolute 'epsilon' of x.

  By default, 'epsilon' is 1e-6.
  """
  epsilon = 0.00000001
  # Check absolute precision.
  if -epsilon <= x - y <= epsilon:
    return True

  # Is x or y too close to zero?
  if -epsilon <= x <= epsilon or -epsilon <= y <= epsilon:
    return False

  # Check relative precision.
  return (-epsilon <= (x - y) / x <= epsilon
       or -epsilon <= (x - y) / y <= epsilon)


########################
# Parsing functions
########################

def read_elements(lines):
	for s in lines:
		for i in s.split(): yield i

class TextGen(object):
	def __init__(self,filename):
		with open(filename,'r') as fichier:
			lines = fichier.readlines()
			self.data = read_elements(lines)

	@property
	def int(self): return int(next(self.data))
	@property
	def str(self): return str(next(self.data))
	@property
	def float(self): return float(next(self.data))
	@property
	def frac(self): return Fraction(float(next(self.data)))
	

########################
# Running...
########################

inname = input("File name ?\n")
infile = "%s.in" % inname
outfile = "%s.out" % inname

inp = TextGen(infile)
cases = inp.int
with open(outfile,'w') as outdata:
	for case in range(1, cases+1):
		print("Starting case %d..." % case)
		outdata.write("Case #%d: %s\n" % (case, algo(inp)))
		print()
