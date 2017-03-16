import itertools

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
 
    # 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
    # Returns a positive value, if OAB makes a counter-clockwise turn,
    # negative for clockwise turn, and zero if the points are collinear.
    def cross(o, a, b):
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])
 
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
 
 
# Example: convex hull of a 10-by-10 grid.
#assert convex_hull([(i/10, i%10) for i in range(100)]) == [(0, 0), (9, 0), (9, 9), (0, 9)]

def powerset(iterable):
	"powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
	s = list(iterable)
	return itertools.chain.from_iterable(itertools.combinations(s, r) for r in range(len(s)+1))

def test(pt, ch):
	for i in range(len(ch)):
		pt1 = ch[i]
		pt2 = ch[(i+1)%len(ch)]
		if pt1 == pt or pt2 == pt:
			return True
		else:
			v1 = (pt1[0] - pt[0],  pt1[1] - pt[1])
			v2 = (pt2[0] - pt[0],  pt2[1] - pt[1])
			if v1[0]*v2[1] == v1[1]*v2[0] and min(pt1[0], pt2[0]) <= pt[0] <= max(pt1[0], pt2[0]) and min(pt1[1], pt2[1]) <= pt[1] <= max(pt1[1], pt2[1]):
				   return True

	return False


for case_no in range(int(raw_input())):
	n = int(raw_input())
	s = []
	for i in range(n):
		s += [tuple(map(int, raw_input().split()))]
	
	mn = [n+1] * n
	
	for comb in powerset(s):
		ch = convex_hull(comb)
		x = n - len(comb)
		#print ch
		for i in range(n):
			
			if test(s[i], ch):
				mn[i] = min(mn[i], x)

	print "Case #%d:" % (case_no+1,)
	for i in mn:
		print i
