from sys import stdin
import sys
if len(sys.argv) > 1:
    sys.stdout = open(sys.argv[1], 'w')

def each_case(R, C, N):
    if N <= (R*C + 1)/2:
        return 0
    if min(R, C) == 1:
        return 2*N - max(R, C) - 1
    if min(R, C) == 2:
        a = N - max(R, C)
        if a > 1: return 3*a - 2
        else: return 2
    if min(R, C) == 3:
        if max(R, C) == 3:
            dd = {6:3, 7:6, 8:8, 9:12}
        elif max(R, C) == 4:
            dd = {7:2, 8:4, 9:7, 10:10, 11:13, 12:17}
        elif max(R, C) == 5:
            dd = {9:3, 10:6, 11:8, 12:11, 13:14, 14:18, 15:22}
        return dd[N]
    dd = {9:2, 10:4, 11:7, 12:10, 13:13, 14:16, 15:20, 16:24}
    return dd[N]

T = int(stdin.readline())
for t in xrange(1,T+1):
    R, C, N = map(int, stdin.readline().split())
    print 'Case #{}: {}'.format(t, each_case(R, C, N))
