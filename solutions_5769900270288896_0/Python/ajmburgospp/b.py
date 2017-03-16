t = int(raw_input())
for kei in xrange(t):
    r, c, n = [int(x) for x in raw_input().split()]
    if (n % 2 == 0 and n * 2 <= r * c) or (n % 2 == 1 and n*2 <= r * c + 1):
        print "Case #%d: 0" % (kei+1, )
    else:
        arr = [[0]*c for _ in xrange(r)]
        def solve(i, j, n):
            if n == 0:
                return 0
            if i == r and j == 0:
                return 1000000
            score = 0
            if i != 0 and arr[i-1][j] == 1:
                score += 1
            if j != 0 and arr[i][j-1] == 1:
                score += 1
            if j+1 >= c:
                ni = i+1
                nj = 0
            else:
                ni = i
                nj = j+1
            cs = 1000000
            if n > 0:
                arr[i][j] = 1
                cs = min(cs, score + solve(ni, nj, n-1))
            arr[i][j] = 0
            cs = min(cs, solve(ni, nj, n))
            return cs
        print "Case #%d: %d" % (kei+1, solve(0, 0, n))
