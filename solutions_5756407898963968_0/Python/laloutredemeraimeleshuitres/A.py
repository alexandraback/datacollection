def get_candidates(f):
    ans = int(f.readline())
    grid = []
    for i in range(4):
        grid.append(map(int, f.readline().strip().split()))
    return grid[ans - 1]

def solve_case(f):
    c0 = get_candidates(f)
    c1 = get_candidates(f)
    sol = [c for c in c0 if c in c1]
    if not sol:
        return "Volunteer cheated!"
    if len(sol) > 1:
        return "Bad magician!"
    return sol[0]

def parse(f):
    ncase = int(f.readline())
    for i in range(ncase):
        print "Case #%d:"%(i+1),
        print solve_case(f)

import sys
parse(sys.stdin)
            
