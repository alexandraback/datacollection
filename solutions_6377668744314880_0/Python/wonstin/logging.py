import string
from collections import defaultdict
import itertools

def ccw(t1, t2, t3):
	return (t2[0]-t1[0])*(t3[1]-t1[1]) - (t2[1]-t1[1])*(t3[0]-t1[0])

def powerset(iterable):
	s = list(iterable)
	return itertools.chain.from_iterable(itertools.combinations(s,r) for r in range(1, len(s)+1))

def convexHull(trees):
	if len(trees) <= 3:
		return trees
	sortedTrees = sorted(trees)
	starting = sortedTrees[0]
	sortedTrees.remove(starting)
	# sort again
	sortedTrees.sort(key=lambda t : (-1, (t[1] - starting[1])/(t[0] - starting[0])) \
		if t[0] > starting[0] else (1, (t[1] - starting[1])/(t[0] - starting[0])) \
		if t[0] < starting[0] else (0, -t[1] - starting[1]))

	ending = sortedTrees[-1]
	hull = [ending, starting] + sortedTrees

	M = 1
	for i in range(2, len(trees)):
		while ccw(hull[M-1], hull[M], hull[i]) < 0:
			if M > 1:
				M -= 1
			elif i == len(trees)-1:
				break
			else:
				i += 1

		M += 1
		hull[M], hull[i] = hull[i], hull[M]

	return hull[:M+1]

def solve(trees):
	print "Solving {}".format(trees)
	bestScores = {}
	for subset in powerset(trees):
		hull = convexHull(subset)
		for boundaryTree in hull:
			if boundaryTree not in bestScores:
				bestScores[boundaryTree] = len(trees) - len(subset)
			else:
				bestScores[boundaryTree] = min(len(trees) - len(subset), bestScores[boundaryTree])

	return "\n" + "\n".join([str(bestScores[tree]) for tree in trees])

def test(inputs, ans):
	b = solve(*inputs)
	if (b != ans):
		print "Failed test! Inputs {} should give answer of {} not {}".format(' '.join(inputs), ans, b)

def main():

    outfile = open('a.out','w')
    T = int(string.strip(raw_input()))    

    for k in xrange(1,T+1):
        print k
        N = int(string.strip(raw_input()))
        trees = []
        for i in range(N):
        	tree = tuple(map(float, raw_input().strip().split()))
        	trees.append(tree)

        answer = solve(trees) # add appropriate arguments
        outfile.write('Case #%d: %s\n' % (k,answer))

if __name__ == '__main__':
    main()