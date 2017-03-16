import itertools

n_cases = input()

def fast(r,c,n):
    coordinates = [(i,j) for i in range(r) for j in range(c)]
    l = [ [(i,j) for (i,j) in coordinates if (i+j)%2 == parity] for parity in range(2) ]
    costs = [0,0]
    
    for parity in [0,1]:
        subset = l[parity][:]
        slots = []
        for (i0,j0) in l[1-parity]:
            t = 0
            if i0 > 0:
                t += 1
            if i0 < r-1:
                t += 1
            if j0 > 0:
                t += 1
            if j0 < c-1:
                t += 1
            slots.append(t)
        
        #print slots
        slots.sort()
        for k in range(n-len(subset)):
            costs[parity] += slots[k]
        #costs[parity] = cost(subset)
        #print '----'
        #m = [['.' for j in range(c)] for i in range(r)]
        #for i,j in subset:
        #    m[i][j] = 'x'
        #print '\n'.join(''.join(row) for row in m)
        #print '----'
    return min(costs)
        
        
        
def solve(r,c,n):
    coordinates = [(i,j) for i in range(r) for j in range(c)]
    best = None
    best_subset = None
    for subset in itertools.combinations(coordinates,n):
        t = cost(subset)
        if best == None or t < best:
            best = t
            best_subset = subset
    #print '----'
    #m = [['.' for j in range(c)] for i in range(r)]
    #for i,j in best_subset:
    #    m[i][j] = 'x'
    #print '\n'.join(''.join(row) for row in m)
    #print '----'
    return best

def cost(subset):
    t = 0
    for i,a in enumerate(subset):
        for j,b in enumerate(subset[i+1:]):
            ai,aj = a
            bi,bj = b
            d = abs(ai-bi) + abs(aj-bj)
            if d == 1:
                t += 1
    return t
    
for i in range(1,n_cases+1):
    r,c,n = map(int,raw_input().split(' '))
    #s = solve(r,c,n)
    f = fast(r,c,n)
    print "Case #%d: %d" % (i, f)