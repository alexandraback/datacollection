#!/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/bin/python2.7

import sys
from decimal import *
import itertools as it
from math import sqrt
from math import floor
from math import ceil
from math import log
from math import log10
import time
import random
import re
import string

inf = float('inf')

def solve(P):
	# if two parties are left, remove the top party one
	# at a time until the parties are equal, then
	# remove one from each party until none left

	# if >2 parties are left, remove the top party
	# until equal to 2nd party, then remove all bottom parties,
	# then drop to 2-party case

	upper = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

	instructions = ''

	N = len(P)

	parties = {upper[i]: P[i] for i in range(N)}

	top_parties = sorted([c for c in parties], key=lambda x:parties[x], reverse=True)
	top_party, sec_party = top_parties[:2]

	#print top_party, sec_party

	instructions += (top_party + ' ') * (parties[top_party] - parties[sec_party])
	parties[top_party] = parties[sec_party]

	for i in range(2,N):
		c = top_parties[i]
		instructions += (c + ' ') * parties[c]

	# remove two at time until all gone
	instructions += (top_party + sec_party + ' ') * parties[top_parties[0]]

	return instructions


def main():
	infile = sys.argv[1]
	f = open(infile,'r')

	T = int(next_line(f))
	for t in range(T):
	    N = int(next_line(f))
	    P = map(int, next_line(f).split())
	    assert len(P) == N
	    print 'Case #{}: {}'.format(t+1, solve(P))

	f.close()

def next_line(f):
    return f.readline().strip()

main()
