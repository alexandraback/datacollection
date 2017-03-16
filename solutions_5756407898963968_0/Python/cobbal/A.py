#!/usr/bin/python

def solve(M, N):
    return M + N

T = int(raw_input())
for caseNum in range(T):
    possibs = set(range(1, 17))
    for n in range(2):
        guess = int(raw_input()) - 1
        grid = [map(int, raw_input().split()) for i in range(4)]
        possibs = possibs & set(grid[guess])
    print "Case #%i:" % (caseNum + 1),
    if len(possibs) == 1:
        print possibs.pop()
    elif not possibs:
        print "Volunteer cheated!"
    else:
        print "Bad magician!"
