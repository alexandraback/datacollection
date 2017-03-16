from sys import stdin, stdout
from ortools.linear_solver import pywraplp

"""
Pretty sure this complies with the CodeJam Rules since or-tools and CBC are both public codebases,
See: https://code.google.com/codejam/faq.html#4-6
"""

def solve(R, C, N):
    solver = pywraplp.Solver("CBC", pywraplp.Solver.CBC_MIXED_INTEGER_PROGRAMMING)

    x = [] #x[r][c]
    for r in range(R):
        x.append([])
        for c in range(C):
            x[r].append(solver.IntVar(0, 1, 'x[%d,%d]'%(r, c)))


    y = {}
    # vert
    for r in range(R):
        for c in range(C-1):
            y[(r,c,r,c+1)] = solver.IntVar(0, 1, 'y[%d,%d,%d,%d]'%(r, c, r, c+1))

    # horiz
    for c in range(C):
        for r in range(R-1):
            y[(r,c,r+1,c)] = solver.IntVar(0, 1, 'y[%d,%d,%d,%d]'%(r, c, r+1, c))
            
            
            
    solver.Minimize( solver.Sum(y.values()) )

    solver.Add( solver.Sum(x[r][c] for r in range(R) for c in range(C)) == N )

    for (r1,c1,r2,c2), yVar in y.items():
        solver.Add( 1 + yVar - x[r1][c1] - x[r2][c2] >= 0 )

    #solver.EnableOutput()
    solver.Solve()

    return int(solver.Objective().Value())



if __name__ == '__main__':

    T = int(stdin.readline())

    for i in range(T):
        # read input for this problem

        R, C, N = map(int, stdin.readline().strip().split())
        result = solve(R, C, N)

        print "Case #%d: %s"%(i+1, result)