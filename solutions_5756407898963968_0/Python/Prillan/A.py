##
# CODEJAM
# prillan91
##
import sys


def solveSingle(f):

    vals = set(x+1 for x in range(16))

    for i in range(2):
        row = int(f.readline())-1
        for j in range(4):
            r = f.readline().strip()
            if j == row:
                vals.intersection_update(int(x) for x in r.split(' '))

    if len(vals) == 1:
        return vals.pop()
    if len(vals) > 1:
        return "Bad magician!"
    if len(vals) == 0:
        return "Volunteer cheated!"

def solve():
    f = open(sys.argv[1])
    o = open(sys.argv[1] + ".out", 'w')
    T = int(f.readline())

    for t in range(T):
        print t + 1
        o.write("Case #" + str(t + 1) + ": " + str(solveSingle(f)) + "\n")

solve()
