#/usr/local/bin/python

import sys
import math

def process_line(line):
    prev = -1
    c    = 0

    ans = [ ]
    for ch in line:
        if ch != prev and c != 0:
            ans.append((prev, c))
            prev = ch
            c = 1
        elif ch != prev:
            prev = ch
            c = 1
        else:
            c += 1

    if c != 0:
        ans.append((prev, c))

    return ans

T = int(sys.stdin.readline())

for caseno in xrange(T):
    N = int(sys.stdin.readline())
    lines = [process_line(sys.stdin.readline().strip()) for x in xrange(N)]
    possible = True


    for l in lines[1:]:
        if len(l) != len(lines[0]):
            possible = False
            break
        for (i, w) in enumerate(l):
            if w[0] != lines[0][i][0]:
                possible = False
                break
        if not possible:
            break

    if not possible:
        print "Case #%d: Fegla Won" % (caseno + 1,)
        continue
        
    M = len(lines[0])

    ans = 0

    for i in xrange(M):

        min_c = 10000
        max_c = 0

        for l in lines:
            min_c = min(min_c, l[i][1])
            max_c = max(max_c, l[i][1])

        cans = max_c * N

        for ca in xrange(min_c, max_c + 1):
            res = 0
            for l in lines:
                res += abs(l[i][1] - ca)

            cans = min(cans, res)

        ans += cans

    print "Case #%d: %s" % (caseno + 1, ans)

