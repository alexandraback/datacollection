# coding='utf-8'

import os, sys, time, random
time.clock()

sys.stdin = open('B-small-attempt0.in')
sys.stdout = open('B-small-attempt0.ans', 'w')

def Work():
	r, c, n = map(int, input().strip().split())
	B = 0
	vlist = []
	for i in range(r):
		for j in range(c):
			if (i + j) % 2 == 1: 
				B += 1
				continue
			ss = 4
			if i == 0: ss -= 1
			if i == r-1: ss -= 1
			if j == 0: ss -= 1
			if j == c-1: ss -= 1
			vlist.append(ss)
	n -= B
	if n <= 0: return 0
	vlist.sort()
	return sum(vlist[:n])

def Work1():
	r, c, n = map(int, input().strip().split())
	ret = 1000000
	for st in range(2**(r*c)):
		zz = [1 if st&(1<<i)>0 else 0 for i in range(r*c)]
		if sum(zz) != n: continue
		rr = 0
		for k, v in enumerate(zz):
			i, j = k // c, k % c
			if v == 0: continue
			if i > 0: rr += zz[(i-1)*c+j]
			if j > 0: rr += zz[i*c+j-1]
		ret = min([ret, rr])
	return ret


if __name__ == '__main__':
	T = int(input())
	for i in range(T): 
		print('Case #%d: %d' % (i+1, Work1()))
	sys.stderr.write('completed %.3f\n' % time.clock())
	
	
