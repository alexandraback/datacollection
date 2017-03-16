# Solution to "Logging" for Google Code Jam 2015
# by Peter Mattsson (quantum.caffeine@gmail.com)
import sys
import heapq

def leftOfLine(point, start, end):
    test = (end[0] - start[0])*(point[1] - end[1]) - \
           (end[1] - start[1])*(point[0] - end[0])
    return test

def solve(n, trees):
    results = []
    for tree in trees:
        bestcutdown = n - 1
        for othertree in trees:
            if othertree == tree:
                continue
            left, right = 0, 0
            for checktree in trees:
                if (checktree == tree) or (checktree == othertree):
                    continue
                test = leftOfLine(checktree, tree, othertree)
                if test > 0:
                    left += 1
                elif test < 0:
                    right += 1
            best = min(left, right)
            if best < bestcutdown:
                bestcutdown = best
        results.append(str(bestcutdown))
    return '\n' + '\n'.join(results)        


def cases():
    with open(sys.argv[1], 'r') as infile:
        numCases = int(infile.readline())
        for _ in range(numCases):
            n = int(infile.readline())
            trees = [[int(x) for x in infile.readline().split()] for _ in xrange(n)]
            yield n, trees

def main():
    with open(sys.argv[2], 'w') as outfile:
        for caseNo, case in enumerate(cases()):
            outfile.write("Case #%d: %s\n"%(caseNo + 1, str(solve(*case))))

if __name__ == "__main__":
    main()
