B = "Bad magician!"
C = "Volunteer cheated!"
for t in xrange(1, input() + 1):
    r1 = input()
    cards1 = [map(int, raw_input().split()) for _ in xrange(4)]
    r2 = input()
    cards2 = [map(int, raw_input().split()) for _ in xrange(4)]
    A = [c for c in cards1[r1 - 1] if c in cards2[r2 - 1]]
    print "Case #{}:".format(t),
    if len(A) == 1:
        print A[0]
    elif len(A) == 0:
        print C
    else:
        print B
