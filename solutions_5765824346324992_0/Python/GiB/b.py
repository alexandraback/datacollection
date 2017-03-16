# -*-coding:utf8 -*
from parsing import TextGen
from fractions import gcd
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
	l_barbs = []
	for _ in range(n_barbs):
		l_barbs.append(inp.int)
	barb_lcmm = lcmm(*l_barbs)
	q_barbs = []
	for (b,mb) in enumerate(l_barbs):
			q_barbs += [(t,b) for t in range(0,barb_lcmm,mb)]
	q_barbs.sort()
	place = place % len(q_barbs)
	(_,res) = q_barbs[place]
	return res + 1


########################

inp = TextGen(infile)
cases = inp.int
with open(outfile,'w') as outdata:
	for case in range(1, cases+1):
		outdata.write("Case #%d: %s\n" % (case, algo(inp)))
