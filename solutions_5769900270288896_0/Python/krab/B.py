import sys
import re

class Teed(object):
    """Wraps a file object. It behaves mostly like the original one,
     but the calls to "write" are replicated to stdout.

     The writelines method is not overriden yet.
     """

    def __init__(self, original):
        self._orig = original

    def write(self, str):
        sys.stdout.write(str)
        self._orig.write(str)

    def __getattr__(self, property):
        """Delagate all other properties
           and method calls to wrapped object"""
        return self._orig.__getattribute__(property)

def main():
    name = re.match(r"^(.*\.)in$", sys.argv[1]).group(1) + "out"

    with open(sys.argv[1]) as f:
        orig_out = sys.stdout
        with open(name, "w") as out_f:
            wrapped = Teed(out_f)
            parse(f, wrapped)

def parse(inp, out):
    cases = int(inp.next().strip())
    for i in range(cases):
        c = parse_case(inp)
        print "Solving case #%d (%s)" % (i + 1, c)
        solution = solve(c)
        print >> out, "Case #%d: %s" % (i + 1, solution)

from itertools import imap, groupby, repeat
from functools import reduce
import operator
import numpy as np

def parse_case(inp):
    return map(int, inp.next().split())

def score(m, n, score_acc=0, min_so_far=99999999999999999):
    # print m, n, score_acc
    if n == 0:
        return score_acc

    rows, cols = m.shape

    for i in range(rows):
        for j in range(cols):
            if not m[i, j]:
                newm = m.copy()
                newm[(i, j)] = True

                added = neighbors(m, (i, j))

                if score_acc + added < min_so_far:
                    s = score(newm, n - 1, score_acc + added)
                    if s < min_so_far:
                        min_so_far = s

    return min_so_far


def neighbors(m, pos):
    possible = [(pos[0] - 1, pos[1]),
                (pos[0], pos[1] -1),
                (pos[0] + 1, pos[1]),
                (pos[0], pos[1] +1)]

    rows, cols = m.shape

    return len([(r, c) for (r, c) in possible
                if 0 <= r < rows
                    and 0 <= c < cols
                    and m[r, c]])

def fill(i, r, c, n, minimum, room):
    counter = 0
    bits = 0

    for row in range(r):
        for col in range(c):
            if counter > minimum:
                return counter
            bit = (i >> (col + c * row)) % 2

            if bit == 1:
                # print "Found", row, col, bin(i)
                bits += 1

                #print row, col
                room[row, col] = True

                if row > 0 and room[row - 1, col]:
                    counter += 1
                if col > 0 and room[row, col - 1]:
                    counter += 1

    # print "bits", bits, n
    if bits == n:
        return counter
    else:
        return 88888888888888888

def solve((r, c, n)):
    minimum = 9999999999999999
    for i in range(2**(r*c)):
        room = np.zeros([r, c], bool)
        counter = fill(i, r, c, n, minimum, room)

        if counter < minimum:
            minimum = counter
        if minimum == 0:
            return 0

###        if i % 1000 == 0:
     #   print "Total", i, counter
    return minimum

    if r * c == n:
        return (r - 1) * c + (c - 1) * r
    if r * c == n + 1:
        return (r - 1) * c + (c - 1) * r - 4

    room = np.zeros([r, c], bool)

    return score(room, n)

if __name__ == "__main__":
    main()
