# Python 3.2

from common import *

def r(s):
    last = None
    counts = []
    chars = []

    for c in s:
        if c == last:
            counts[-1] += 1
        else:
            last = c
            chars.append(c)
            counts.append(1)
    return (chars, counts)

def least(counts):
    counts.sort()
    k = len(counts)
    opt = counts[k // 2]

    moves = 0
    for count in counts:
        moves += abs(count - opt)
    return moves

def main(casenum):
    n = readint()
    ss = []
    for i in range(n):
        ss.append(readline())

    countss = []
    chars, counts = r(ss[0])
    for count in counts:
        countss.append([count])

    valid = True

    for i in range(1, n):
        chars_, counts = r(ss[i])
        if chars != chars_:
            valid = False
            break

        for i, count in enumerate(counts):
            countss[i].append(count)

    if valid:
        moves = 0
        for counts in countss:
            moves += least(counts)

        writeline('Case #{}: {}'.format(casenum, moves))
    else:
        writeline('Case #{}: Fegla Won'.format(casenum))

run(main)
