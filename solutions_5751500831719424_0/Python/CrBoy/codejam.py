#!/usr/bin/env python3

from sys import stdin
import math

def codejam(f):
	cases = int(stdin.readline())
	for case in range(1, cases+1):
		print('Case #%d: %s' % (case, f()))

