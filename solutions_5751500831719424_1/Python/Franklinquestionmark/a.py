#!python3
#000000001111111111222222222233333333334444444444555555555566666666667777777777
#234567890123456789012345678901234567890123456789012345678901234567890123456789

def process():
	### INPUT ###
	'''
	 Each test case starts with a line containing an integer N which is the number of strings. Followed by N lines, each line contains a non-empty string (each string will consist of lower case English characters only, from 'a' to 'z'). 
	'''
	N = eat(int)
	strs = eat([str]*N)
	
	### COMPUT ###
	# 1 <= length of each string <= 100. 
	# 2 <= N <= 100. 
	def toarr(s):
		last = None
		counts = []
		for c in s:
			if last == c:
				counts[-1][-1] +=1
			else:
				counts.append([c,1])
				last = c
		return counts
	FEGLA = "Fegla Won"
	def solve():
		ray = list(map(toarr, strs))
		if len(set(tuple(map(lambda x: x[0], arr)) for arr in ray)) != 1:
			#print (set(tuple(map(lambda x: x[0], arr)) for arr in ray), file=stderr)
			return FEGLA
		L = len(ray[0])
		ray = [[ct for c, ct in arr] for arr in ray] #remove the chars then
		ray = list(zip(*ray)) #and transpose
		
		#brute it
		moves = sum(min(sum(abs(x-i) for x in arr) for i in range(min(arr), max(arr)+1)) for arr in ray)
		return moves
	
	### OUTPUT ###
	return solve()



#########################     busyworks     ###############################

def main():
	T = eat(int)
	for i in range(1, T+1):
		print('Case #%d:'%i, process())

def tokenizer(file=None):
	'''generates tokens from a file source'''
	if file == None:
		from sys import stdin
		file = sys.stdin
	for line in file:
		yield from line.split()

def eat(shape, cin=tokenizer()):
	if callable(shape):
		return shape(next(cin))
	#otherwise it's a sequence
	#return the same kind of sequence
	return type(shape)(eat(typ, cin) for typ in shape)

def eats(*shapes, cin=None):
	if cin is None:
		return eat(shapes)
	return eat(shapes, cin)

#########################     imports     ###############################

import sys
from sys import stdin, stdout, stderr, argv
import os

import functools
import functools as ftools
# from functools import *
from functools import (
	partial,
	partial as bind,
	lru_cache,
	reduce,
)
memoize = bind(lru_cache, maxsize=None)
import itertools
import itertools as itools
from itertools import *

from operator import * #iterable and such
from random import (
	random,
	randint,
	randrange,
	shuffle,
)
import collections
from collections import *
from collections import(
	defaultdict as ddict,
	OrderedDict as odict,
)
import queue
from queue import(
	PriorityQueue,
	PriorityQueue as pqueue, #min first
)
import re
import numpy
import numpy as np
from numpy import(
	array,
)
import math
from math import *
from math import(
	sqrt,
	log as ln,
	log10,
	log2,
	log2 as lg,
)
del log #ugh
import cmath
#import fractions

#########################     main     ###############################
main()
