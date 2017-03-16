# http://code.google.com/codejam/contest/4314486/dashboard#s=p0
from collections import defaultdict
from re import match
from numpy import array, argsort
from time import sleep
from numpy.linalg import matrix_rank

def biggest(a,N): return argsort(a)[::-1][:N]
def absolute(ls): s = int(sum(ls)/2);return any(e>s or e<0 for e in ls)

def read_file(fname):
	res = []
	with open(fname,"r") as f:
		data = [l.strip() for l in f.readlines()][1:]
		for N, Ps in zip(data[::2],data[1::2]):
			res.append(list(map(int, Ps.split(" "))))
	return res

def solve_all(fname):
	problems = read_file("%s.in" % fname)
	case = 1
	text = ""
	for p in problems:
		print("Solving Case #%s" % case)
		res = solve(p)
		text += "Case #%s: %s\n" % (case, res)
		case+=1
	with open("%s.out" % fname, "w") as out:
		out.write(text)

def solve(Ps):
	return bt(Ps, [])

mask = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def bt(Ps, steps):
	# generate alternatives
	big1, big2 = biggest(Ps, 2)
	res = Ps[:]
	res[big1]-=1
	res[big2]-=1
	if absolute(res):
		res[big2]+=1
		steps.append(mask[big1])
	else:
		steps.append(mask[big1]+mask[big2])

	if all(e==0 for e in res):
		return " ".join(steps)
	else:
		return bt(res,steps)


solve_all("large")