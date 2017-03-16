t = int(raw_input())
for kei in xrange(t):
    r, c, n = [int(x) for x in raw_input().split()]
    if (r*c%2 == 0 and n * 2 <= r * c) or (r*c%2 == 1 and n*2 <= r * c + 1):
        print "Case #%d: 0" % (kei+1, )
    elif r == 1 or c == 1:
        n -= r*c/2
        cost = 0
        if r*c%2 == 0:
            edges = 1
        else:
            edges = 2
        if n > 0:
            cost += min(edges, n)
            n -= min(edges, n)
        if n > 0:
            cost += 2 * n
        print "Case #%d: %d" % (kei+1, cost)
    else:
        on = n
        n -= r*c / 2
        cost = 0
        if r*c % 2 == 0:
            corners = 2
        else:
            corners = 4
        edges = r+c-2-corners
        cost += min(corners, n) * 2
        n -= min(corners, n)
        if n > 0:
            cost += min(edges, n) * 3
            n -= min(edges, n)
        if n > 0:
            cost += n * 4
        if r*c % 2 == 1 and on == r*c / 2 + 2:
            cost -= 1
        print "Case #%d: %d" % (kei+1, cost)
