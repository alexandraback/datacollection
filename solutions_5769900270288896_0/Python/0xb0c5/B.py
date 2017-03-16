import itertools

n_cases = input()


def solve(r,c,n):
    coordinates = [(i,j) for i in range(r) for j in range(c)]
    best = None
    for subset in itertools.combinations(coordinates,n):
        cost = 0
        for i,a in enumerate(subset):
            for j,b in enumerate(subset[i+1:]):
                ai,aj = a
                bi,bj = b
                d = abs(ai-bi) + abs(aj-bj)
                if d == 1:
                    cost += 1
        if best == None or cost < best:
            best = cost
    return best

for i in range(1,n_cases+1):
    r,c,n = map(int,raw_input().split(' '))
    print "Case #%d: %d" % (i, solve(r,c,n))