import sys


def solve(case, row1, grid1, row2, grid2):
    s = set(grid1[row1]) & set(grid2[row2])
    l = len(s)
    if l == 0:
        print "Case #%d: Volunteer cheated!" % case
    elif l == 1:
        print "Case #%d: %s" % (case, list(s)[0])
    else:
        print "Case #%d: Bad magician!" % case


if __name__ == '__main__':
    f = sys.stdin
    t = int(f.readline())
    for i in xrange(1, t+1):
        row1 = int(f.readline()) - 1
        grid1 = []
        for j in xrange(4):
            grid1.append(f.readline().split())
        row2 = int(f.readline()) - 1
        grid2 = []
        for j in xrange(4):
            grid2.append(f.readline().split())
        solve(i, row1, grid1, row2, grid2)

           
