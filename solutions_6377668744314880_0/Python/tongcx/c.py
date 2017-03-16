from sys import stdin, stderr

T = int(stdin.readline())

for _ in range(T):
    N = int(stdin.readline())
    points = [map(int, stdin.readline().split()) for i in range(N)]

    print 'Case #{}:'.format(_+1)
    print >> stderr, 'x <- c({})'.format(','.join([str(p[0]) for p in points]))
    print >> stderr, 'y <- c({})'.format(','.join([str(p[1]) for p in points]))

    ans = []

    for base in points:
        best = N

        for pivot in points:
            if base != pivot:
                pos = 0
                neg = 0

                for p in points:
                    cross = (p[0] - base[0]) * (pivot[1] - base[1]) - (p[1] - base[1]) * (pivot[0] - base[0])
                    if cross > 0:
                        pos += 1
                    elif cross < 0:
                        neg += 1

                best = min(best, pos, neg)

        print best
        ans.append(best)

    print >> stderr, 'ans <- c({})'.format(','.join(map(str, ans)))
    print >> stderr, 'qplot(x,y) + geom_text(aes(label=ans),vjust=-1)'
    print >> stderr
