import sys
import math

def solve(r, c, n):
    if n <= math.ceil(r * c * 0.5):
        return 0
    empty = r * c - n
    unhap = (c - 1) * r + (r - 1) * c

    if r % 2 == 1 and c % 2 == 1:
        corner_empty = 4
    else:
        corner_empty = 2
    middle_empty = (r - 2) * (c - 2) * 0.5
    if middle_empty > 0:
        middle_empty = math.ceil(middle_empty)
    else:
        middle_empty = 0
    edge_empty = math.ceil(r * c * 0.5) - middle_empty - corner_empty
    if edge_empty <= 0:
        edge_empty = 0

    if empty >= middle_empty:
        unhap -= middle_empty * 4
        empty -= middle_empty
    else:
        unhap -= empty * 4
        empty = 0

    if empty >= edge_empty:
        unhap -= edge_empty * 3
        empty -= edge_empty
    else:
        unhap -= empty * 3
        empty = 0

    if empty >= corner_empty:
        unhap -= corner_empty * 2
        empty -= corner_empty
    else:
        unhap -= empty * 2
        empty = 0

    if empty > 0:
        import pdb
        pdb.set_trace()

    return int(unhap)

def main(inFile):
    with open(inFile) as inp, open(inFile.replace('.in', '.out'), 'w') as out:
        T = int(inp.readline().strip())
        for t in xrange(T):
            R, C, N = [int(x) for x in inp.readline().strip().split()]
            out.write('Case #%d: %s\n' % (t + 1, solve(R, C, N)))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit('Usage: %s input.in' % sys.argv[0])
    main(sys.argv[1])
