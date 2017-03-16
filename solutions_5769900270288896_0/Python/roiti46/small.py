import itertools as it
dxy = zip([1, 0, -1, 0], [0, 1, 0, -1])
T = int(raw_input())
for case in xrange(1, T + 1):
    R, C, N = map(int, raw_input().split())
    ans = 1000 if N > 0 else 0
    for exist in it.combinations(range(R * C), N):
        room = [[False] * C for i in xrange(R)]
        for i in exist:
            room[i / C][i % C] = True

        tmp = 0
        for y in xrange(R):
            for x in xrange(C):
                if room[y][x]:
                    for dx, dy in dxy:
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < C and 0 <= ny < R and room[ny][nx]:
                            tmp += 1
                    room[y][x] = False
                    
        ans = min(ans, tmp)
    print "Case #%d: %d" % (case, ans)
