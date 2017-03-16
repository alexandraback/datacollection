import math
import sys
import fractions

sys.setrecursionlimit(2 ** 20)

input = open('date.in', 'r')
output = open('date.out', 'w')

di = [ 0, 1, 0, -1 ]
dj = [ 1, 0, -1, 0 ]

def solve(R, C, N):
    K = R * C
    A = [ [ False for j in range(C) ] for i in range(R) ]
    ans = 10000000
    for mask in range(1 << K):
        cnt = bin(mask).count('1')
        if cnt == N:
            for i in range(R):
                for j in range(C):
                    A[i][j] = False
            for b in range(K):
                if (mask & (1 << b)) > 0:
                    i = b / C
                    j = b % C
                    A[i][j] = True
            cost = 0
            for i in range(R):
                for j in range(C):
                    if A[i][j]:
                        for d in range(4):
                            ni = i + di[d]
                            nj = j + dj[d]
                            if ni >= 0 and ni < R and nj >= 0 and nj < C and A[ni][nj]:
                                cost += 1
            cost /= 2
            ans = min(ans, cost)
    return ans

T = int(input.readline())
for t in range(T):
    line = input.readline().strip().split(' ')
    R = int(line[0])
    C = int(line[1])
    N = int(line[2])
    ans = solve(R, C, N)
    output.write('Case #{}: {}\n'.format(t + 1, ans))
    print t

input.close()
output.close()