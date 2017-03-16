################################################################
def solve():
    N, = [int(x) for x in input.readline().split(' ')]
    S = [input.readline().strip('\n') for _ in range(N)]
    if not possible(S):
        return 'Fegla Won'
    A = [counts(s) for s in S]
    B = [[c[i] for c in A] for i in range(len(A[0]))]
    return sum([moves(x) for x in B])


def moves(S):
    S.sort()
    n = len(S)
    median = S[n / 2]
    return sum([abs(x - median) for x in S])


def strip_repeats(s):
    result = [s[0]]
    for i in range(1, len(s)):
        if s[i] != s[i-1]:
            result.append(s[i])
    return "".join(result)


def counts(s):
    result = [1]
    for i in range(1, len(s)):
        if s[i] == s[i-1]:
            result[-1] += 1
        else:
            result.append(1)
    return result


def possible(S):
    l = [strip_repeats(s) for s in S]
    return l[1:] == l[:-1]

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
