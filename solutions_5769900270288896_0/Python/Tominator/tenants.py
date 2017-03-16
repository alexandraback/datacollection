
import sys, collections

def read():
    return sys.stdin.readline().strip()


def calculate_cost(Map, R, C):
    total = 0
    for r in xrange(R):
        for c in xrange(C):
            if Map[r,c] and Map[r+1, c]:
                total += 1
            if Map[r,c] and Map[r, c+1]:
                total += 1
    return total

def optimal(R, C, N):
    Map = collections.defaultdict(int)
    for i, cell in zip(xrange(N), Cells(R, C)):
        Map[cell] = 1

    current_cost = calculate_cost(Map, R, C)

    while True:
        Map = try_to_swap(Map, R, C)
        if Map:
            current_cost = calculate_cost(Map, R, C)
        else:
            return current_cost

def Cells(R, C):
    return [(r, c) for r in xrange(R) for c in xrange(C)]

def try_to_swap(Map, R, C):
    cost = calculate_cost(Map, R, C)

    for cell1 in Cells(R, C):
        if not Map[cell1]: continue

        for cell2 in Cells(R, C):
            if Map[cell2]: continue

            Map2 = collections.defaultdict(int)
            Map2.update(Map)
            Map2[cell1] = 0
            Map2[cell2] = 1

            cost2 = calculate_cost(Map2, R, C)

            if cost2 < cost:
                return Map2

num_cases = int(read())
for case in xrange(num_cases):
    R, C, N = [int(x) for x in read().split(" ")]
    print "Case #%d: %d" % (case+1, optimal(R, C, N))

