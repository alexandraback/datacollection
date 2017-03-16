# -*-coding:utf8 -*
from parsing import TextGen
from fractions import gcd
from queue import PriorityQueue
from math import floor
import functools
infile = "b.in"
outfile = "b.out"

########################
def lcm(a,b): return (a // gcd(a,b)) * b
def lcmm(*args) : return functools.reduce(lcm, args)

def merge_barb(*barbs):
	n = lcm(a1,a2)
	

def algo(inp):
	n_barbs = inp.int
	place = inp.int - 1
	cps = 0.0
	l_barbs = []
	for _ in range(n_barbs):
		mb = inp.int
		l_barbs.append(mb)
		cps += 1/mb
	if place < n_barbs: return place+1
	time_approx = floor((place-n_barbs)/cps)
	clients_passed = 0
	que = PriorityQueue()
	for (barb,mb) in enumerate(l_barbs):
		clients_b = time_approx // mb + 1
		clients_passed += clients_b
		que.put((clients_b*mb , (barb,mb)))
	barb_res = 0
	while clients_passed <= place:
		(t,(barb,mb)) = que.get()
		barb_res = barb
		clients_passed += 1
		que.put((t+mb,(barb,mb)))
	return barb_res + 1
		


########################

inp = TextGen(infile)
cases = inp.int
with open(outfile,'w') as outdata:
	for case in range(1, cases+1):
		outdata.write("Case #%d: %s\n" % (case, algo(inp)))
