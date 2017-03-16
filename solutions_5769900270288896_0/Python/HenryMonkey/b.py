import sys

input = file(sys.argv[1]).readline

def solution(x):
    r = x[0]
    c = x[1]
    n = x[2]
    if n <= (r*c+1)/2:
        return 0
    dp2 = [[(i+j)%2 for i in xrange(1,r+1)] for j in xrange(1,c+1)]
    dp1 = [[(i+j+1)%2 for i in xrange(1,r+1)] for j in xrange(1,c+1)]
    n1 = n - (r*c+1)/2
    n2 = n - r*c/2
    ans1 = 0
    ans2 = 0
    q1 = 0
    q2 = 0
    odd = True
    if r == 1 or c == 1:
        if r*c%2 == 1:
            return 2*n1
        return 1+2*(n1-1)
    for i in xrange(1,r-1):
        if dp1[0][i] == 0:
            q1 += 1
        if dp2[0][i] == 0:
            q2 += 1
        if dp1[-1][i] == 0:
            q1 += 1
        if dp2[-1][i] == 0:
            q2 += 1
    for i in xrange(1,c-1):
        if dp1[i][0] == 0:
            q1 += 1
        if dp2[i][0] == 0:
            q2 += 1
        if dp1[i][-1] == 0:
            q1 += 1
        if dp2[i][-1] == 0:
            q2 += 1
    a1, a2 = 0,0
    for i in [0,-1]:
        for j in [0,-1]:
            if dp1[i][j] == 0:
                a1 += 1
            if dp2[i][j] == 0:
                a2 += 1
    if n1 <= a1:
        ans1 = 2*n1
    else:
        ans1 = 2*a1
        n1 -= a1
        ans1 += 3*min(n1,q1) + 4*max(0,n1-q1)
    if n2 <= a2:
        ans2 = 2*n2
    else:
        n2 -= a2
        ans2 = 2*a2
        ans2 += 3*min(n2,q2) + 4*max(0,n2-q2)
    return min(ans1,ans2)





for case in xrange(int(input())):
	x = [int(i) for i in input().strip().split(' ')]
	print "Case #%d: %d " % (case+1, solution(x))
