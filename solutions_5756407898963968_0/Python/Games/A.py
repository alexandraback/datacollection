################################################################
def solve():
    candidates = set(range(1, 17))
    for i in range(2):
        guess = int(input.readline())
        cards = [set([int(x) for x in input.readline().split(' ')])
                 for i in range(4)]
        candidates = candidates.intersection(cards[guess-1])
    if len(candidates) == 0:
        return "Volunteer cheated!"
    elif len(candidates) == 1:
        return candidates.pop()
    else:
        return "Bad magician!"
################################################################

from datetime import datetime
time_start = datetime.today()


def now():
    return datetime.today() - time_start

import sys
infilename = sys.argv[1]
outfilename = infilename.replace('.in', '.out')

input = open(sys.argv[1], 'r')
output = open(sys.argv[1].replace('.in', '.out'), 'w')
n = int(input.readline())

for i in range(1, n+1):
    result = solve()
    print "Case #%d: %s \t %s" % (i, result, now())
    output.write("Case #%d: %s\n" % (i, result))
    output.flush()
