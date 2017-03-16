import random
import sets

def makeState(R,C):
    empty_cells = set([ (i,j) for i in range(R) for j in range(C) ])
    return empty_cells

def unhappiness(R, C, state, pair):
    u = 0
    r,c = pair
    if r > 0:
        if (r-1,c) not in state:
            u += 1
    if r < R-1:
        if (r+1,c) not in state:
            u += 1
    if c > 0:
        if (r,c-1) not in state:
            u += 1
    if c < C-1:
        if (r,c+1) not in state:
            u += 1
    return u


visited = set()
best = 0
def backtrack(R, C, state, N, k, cost=0):
    global best
    global visited
    if k == N:
        best = min(best,cost)
    else:
        aux = sets.ImmutableSet(state)
        visited.add(aux)
        l = list(state)
        for i in range(len(l)):
            u = unhappiness(R, C, state, l[i])
            if cost+u < best:
                state.remove(l[i])
                aux = sets.ImmutableSet(state)
                if not aux in visited:
                    backtrack(R, C, state, N, k+1, cost + u)
                state.add(l[i])

T = int(raw_input())
for i in range(T):
    R,C,N = map(int, raw_input().split())
    if N == 0:
        best = 0
    else:
        best = (R*(C-1) + C*(R-1))
        visited = set()
        backtrack(R,C,makeState(R,C),N,0)
    print "Case #%d: %d"%(i+1,best)
