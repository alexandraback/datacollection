#!/usr/bin/env python3

import itertools

def leftturn(pt1, pt2, pt3):
	x1, y1 = pt1
	x2, y2 = pt2
	x3, y3 = pt3
	v1x, v1y = x2 - x1, y2 - y1
	v2x, v2y = x3 - x2, y3 - y2
	cross = v1x * v2y - v2x * v1y
	return cross > 0 #or len(set([pt1, pt2, pt3])) != 3
	

def chull(pts):
	pts = pts[:]
	d = False#pts == [(0, 0), (5, 0), (0, 5), (5, 5), (0, 10), (5, 10), (10, 10)]
	pts.sort()

	pts = pts + pts[::-1][1:]
	if d: print('pts:', pts)
	hull = pts[:2]
	for pt in pts[2:]:
		hull.append(pt)
		while len(hull) >= 3 and leftturn(*hull[-3:]):
			hull.pop(len(hull)-2)
		if d:
			print('    ', hull)
			
	return hull[:-1]
	

def doprob(caseno):
	n = int(input())
	pts = [tuple(map(int, input().split())) for i in range(n)]
	
	hsize = len(chull(pts))
	#print(sorted(pts))
	#print(chull(pts))
	
	# Brute forcey
	sizes = {pt:n-1 for pt in pts}
	for size in range(2, n+1):
		for comb in itertools.combinations(pts, size):
			p = list(comb)
			for pt in chull(p):
				sizes[pt] = min(sizes[pt], n-size)
	
	print('Case #%d:' % caseno)
	for pt in pts:
		print(sizes[pt])
		

ncases = int(input())
for caseno in range(1, ncases+1):
	doprob(caseno)
