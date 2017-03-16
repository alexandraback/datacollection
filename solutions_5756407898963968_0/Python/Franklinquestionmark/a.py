#!python3
#A. Magic trick

def process(cin):
	ans1 = cin.int
	cards1 = [cin.line(int) for _ in range(4)][ans1-1]
	ans2 = cin.int
	cards2 = [cin.line(int) for _ in range(4)][ans2-1]
	
	def solve():
		#cards that fit the descriptions
		cards = [c for c in cards1 if c in cards2]
			#? c = list(filter(cards1.__in__, cards2))
		if len(cards)>1: #multiple cards
			return 'Bad magician!'
		elif len(cards) == 0: #no cards
			return 'Volunteer cheated!'
		else:
			return cards[0]
		
	return solve()





'$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'
'$                         main                          $'
'$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'

def main(cin, cout):
	T = cin.int
	for i in range(1,T+1):
		print('Case #%d:'%i, process(cin), file=cout)

'$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'
'$                     functions                         $'
'$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'

#https://docs.python.org/3.4/library/bisect.html
def indexof(a, x):
    'Locate the leftmost value exactly equal to x'
    i = bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    raise ValueError

def find_lt(a, x):
    'Find rightmost value less than x'
    i = bisect_left(a, x)
    if i:
        return a[i-1]
    raise ValueError

def find_le(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect_right(a, x)
    if i:
        return a[i-1]
    raise ValueError

def find_gt(a, x):
    'Find leftmost value greater than x'
    i = bisect_right(a, x)
    if i != len(a):
        return a[i]
    raise ValueError

def find_ge(a, x):
    'Find leftmost item greater than or equal to x'
    i = bisect_left(a, x)
    if i != len(a):
        return a[i]

'$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'
'$                         Imports                       $'
'$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'

import sys
from sys import stdin, stdout, stderr, argv
import os

import functools
import functools as ftools
# from functools import *
from functools import (
	partial,
	partial as fixarg,
	lru_cache,
	lru_cache as memoize,
)
import itertools
import itertools as itools
from itertools import *

from operator import *
from random import (
	random,
	randint,
	randrange,
	shuffle,
)
from collections import(
	defaultdict,
	defaultdict as ddict,
	OrderedDict,
	OrderedDict as odict,
)
from queue import(
	PriorityQueue,
	PriorityQueue as pqueue, #min first
)
import re
import numpy
import numpy as np
import math
from math import(
	sqrt,
	log as ln,
	log10,
	log2,
	log2 as lg,
)
import cmath

def ith(i):
	return lambda tupl: tupl[i]

first, second, third = map(ith, range(3))
last = ith(-3)
rest = ith(slice(1,None))

def max_idx(iterable):
	return first(max(enumerate(iterable), key=second))

#import fractions

class istream:
	'''
	Use as:
		cin = istream()
		cin = istream(s)
		cin = istream(open(fname))
		cin.int
		cin.get(int)
		cin.get(float)
		cin.get(str)
		# cin.get(chr) #ugh need to have a better buffer
		cin[int]
		cin.line()
		cin.lineas(int)
		cin.list(int)
		# cin.line(delim)
		# cin.lines()
		# int(cin)?
		next(cin) #next token
	'''
	def __init__(self, src=stdin):
		if type(src) == str:
			src = src.splitlines()
		self.src = iter(src)
		self.buf = None
	def get(self, typ):
		return typ(next(self))
	def __getattr__(self, typ):
		return eval(typ)(next(self))
	
	__getitem__ = get
	__call__ = get
	def __iter__(self): return self
	def line(self, typ=None):
		"""Empty the buffer and return it, or get the next line if it's not empty."""
		if typ is not None:
			return self.lineas(typ)
		if self.buf is not None:
			rv = self.buf
			self.buf = None
			return rv
		else:
			rv = next(self.src).strip('\n')
		return rv #does next work on stdin?
	def __next__(self):
		"""get the next space-delimited token"""
		buf = None
		while buf is None or len(buf.strip()) == 0:
			buf = self.line()
		#split once
		token, *rest = buf.split(maxsplit=1)
		self.buf = rest[0] if rest else None
		return token
	def lineas(self, typ=None):
		if typ is None:
			return self.line()
		return list(map(typ, self.line().split()))
	list = lineas


if __name__ == "__main__":
	if len(argv) > 1:
		infile = argv[1]
		if len(argv) > 2:
			outfile = argv[2]
		else:
			outfile = os.path.splitext(infile)[0]+'.out'
		with open(infile, 'r') as fin:
			with open(outfile, 'w') as fout:
				main(istream(fin), fout)
	else:
		main(cin=istream(stdin), cout=stdout)
