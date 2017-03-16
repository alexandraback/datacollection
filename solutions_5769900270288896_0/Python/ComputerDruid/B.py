#!/usr/bin/env python3
from itertools import combinations

class Problem:
    def __init__(self, R, C, N):
        self.R = R
        self.C = C
        self.N = N
        self.grid = [[False] * (C+1) for r in range(R+1)]
    def count(self,choices):
        choices = frozenset(choices)
        for r in range(self.R):
            for c in range(self.C):
                self.grid[r][c] = (r*self.R + c in choices)
        u = 0
        for r in range(self.R):
            for c in range(self.C):
                if self.grid[r][c] and self.grid[r][c+1]:
                    u +=1
                if self.grid[r][c] and self.grid[r+1][c]:
                    u +=1
        return u

    def solve(self):
        return min((self.count(b) for b in combinations(range(self.R*self.C), self.N)))

def solve(R, C, N):
    return Problem(R,C,N).solve()

T = int(input())
for t in range(T):
    R, C, N = [int(x) for x in input().split(" ")]
    print("Case #" + str(t+1) +":", solve(R, C, N))
