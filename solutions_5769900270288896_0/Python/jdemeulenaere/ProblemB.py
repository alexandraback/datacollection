import itertools
import sys

data = open("input/problemb.txt")
nb_cases = int(data.readline())

for z in xrange(nb_cases):
    print "Case #%d:" % (z + 1),

    R,C,N = [int(x) for x in data.readline().split(" ")]

    position = [x for x in xrange(R*C)]
    perms = itertools.combinations(position, N)

    min_v = sys.maxint
    for perm in perms:
        counter = 0
        tab = [[0 for _ in xrange(C)] for _ in xrange(R)]
        for pos in perm:
            x = pos / C
            y = pos % C
            tab[x][y] = 1

        for x in xrange(R):
            for y in xrange(C-1):
                if tab[x][y] == 1 and tab[x][y+1] == 1:
                    counter += 1

        for x in xrange(R-1):
            for y in xrange(C):
                if tab[x][y] == 1 and tab[x+1][y] == 1:
                    counter += 1

        min_v = min(min_v, counter)
    print min_v