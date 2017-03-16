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
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) < 0: #changed!
            lower.pop()
        lower.append(p)
 
    # Build upper hull
    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) < 0: #changed!
            upper.pop()
        upper.append(p)
 
    # Concatenation of the lower and upper hulls gives the convex hull.
    # Last point of each list is omitted because it is repeated at the beginning of the other list. 
    return lower[:-1] + upper[:-1]

def solve(n, c):
	res = [n for _ in range(n)]
	for i in range(1<<n):
		chosenPoints = [(x[0], x[1], j) for j, x in enumerate(c) if ((1<<j) & i) != 0]
		convexHull = convex_hull(chosenPoints)
		removed = n-len(chosenPoints)
		for x, y, j in convexHull:
			res[j] = min(res[j], removed)
	return res

def main():
	t = int(raw_input())
	for tt in range(1, t+1):
		n = int(raw_input())
		c = []
		for _ in range(n):
			c.append(tuple(map(int, raw_input().split(' '))))
		print('Case #{0}:'.format(tt))
		for x in solve(n, c):
			print(x)

if __name__ == '__main__':
	main()