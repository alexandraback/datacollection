#!/usr/bin/python

import sys
import math
from itertools import chain, combinations

# 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
# Returns a positive value, if OAB makes a counter-clockwise turn,
# negative for clockwise turn, and zero if the points are collinear.
def cross(o, a, b):
    return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])


#print cross((0,0), (1,1), (2,6))

def convex_hull(points):
    """Computes the convex hull of a set of 2D points.
    Input: an iterable sequence of (x, y) pairs representing the points.
    Output: a list of vertices of the convex hull in counter-clockwise order,
      starting from the vertex with the lexicographically smallest coordinates.
    Implements Andrew's monotone chain algorithm. O(n log n) complexity.
    """
    # Sort the points lexicographically (tuples are compared lexicographically).
    # Remove duplicates to detect the case we have just one unique point.
    points = sorted(set(points))
 
    # Boring case: no points or a single point, possibly repeated multiple times.
    if len(points) <= 1:
        return points
 
    # Build lower hull 
    lower = []
    for p in points:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) <= 0:
            lower.pop()
        lower.append(p)
 
    # Build upper hull
    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) <= 0:
            upper.pop()
        upper.append(p)
 
    # Concatenation of the lower and upper hulls gives the convex hull.
    # Last point of each list is omitted because it is repeated at the beginning of the other list. 
    return lower[:-1] + upper[:-1]

#print convex_hull([(0,0), (1,1), (2,2), (3,0)])


def isBetween((ax,ay), (bx,by), (cx,cy)):
    crossproduct = (cy - ay) * (bx - ax) - (cx - ax) * (by - ay)
    if abs(crossproduct) != 0 : return False   # (or != 0 if using integers)

    dotproduct = (cx - ax) * (bx - ax) + (cy - ay)*(by - ay)
    if dotproduct < 0 : return False

    squaredlengthba = (bx - ax)*(bx - ax) + (by - ay)*(by - ay)
    if dotproduct > squaredlengthba: return False

    return True

def powerset(iterable):
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

def onBoundary(P, hull):
	if P in hull:
		return True
	for i in range(len(hull)):
		if isBetween(hull[i], hull[(i+1)%len(hull)], P):
			return True
	return False

def getBoundary(pts, hull):
	return [P for P in pts if onBoundary(P, hull)]


def solve(N, pts):
	#hull = convex_hull(pts).reverse()
	MAX = 100
	best = [MAX for _ in pts]
	for subset in powerset(pts):
		subset = list(subset)
		hull = convex_hull(subset)
		hull.reverse()
		#print hull
		#print hull
		if hull is not None:
			boundary = set(getBoundary(subset, hull))
			#print "boundary", boundary
			for i in range(N):
				if pts[i] in boundary:
					#print "EHLLO?"
					best[i] = min(best[i], N-len(subset))

	return best


if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		N = int(sys.stdin.readline())
		pts = []
		for i in range(N):
			Xi, Yi = map(int, sys.stdin.readline().split())
			pts.append((Xi, Yi))

		print "Case #{}:".format(t+1)
		for best in solve(N, pts):
			print best
