def solve(r,c,n, occupied=None):
    if occupied is None:
        occupied = [[None for j in range(r)] for i in range(c)]
        #print(occupied)
        if n == r*c:
            return c*(r-1) + r*(c-1)
        if n == 0:
            return 0
        occupied [0][0] = 1
        return solve(r,c, n-1, occupied)
    if n == 0:
        return 0
    mem = memo[r-1][c-1].get(tupelize(occupied), None)
    if mem is not None:
        return mem
    m = c*(r-1) + r*(c-1)
    #import pdb
    #pdb.set_trace()
    #print(r,c,n)
    #print(occupied)
    for i in range(r):
        for j in range(c):
            if occupied[j][i] is None: # Occupy
                cost = 0

                #print(r,c)
                if j > 0 and occupied[j-1][i]:
                    cost += 1
                if j < (c - 1) and occupied[j+1][i]:
                    cost += 1
                if i > 0  and occupied[j][i-1]:
                    cost += 1
                if i < (r - 1) and occupied[j][i+1]:
                    cost += 1
                occupied[j][i] = 1
                ne = solve(r,c,n-1, occupied)
                occupied[j][i] = None
                m = min(cost + ne, m)
    memo[r-1][c-1][tupelize(occupied)] = m
    return m

in_file = open("occ.in")
N = int(in_file.readline().strip())

def tupelize(l):
    return tuple(tuple(j) for j in l)


for j in range(N):
    r, c, n = map(int, in_file.readline().strip().split())
    #print(r,c,n)
    #print(min(r,c),max(c,r),n)
    memo = [[dict() for j in range(max(r,c))] for k in range(min(r,c))]
    print("Case #" + str(j+1) + ": " + str(solve(min(r,c),max(c,r),n)))










