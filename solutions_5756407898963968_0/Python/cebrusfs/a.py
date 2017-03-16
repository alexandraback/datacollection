T = int(raw_input())
for zi in xrange(1, T+1):

    r1 = int(raw_input()) - 1
    A = [raw_input().split(" ") for _ in xrange(4)][r1]
    r2 = int(raw_input()) - 1
    B = [raw_input().split(" ") for _ in xrange(4)][r2]

    C = set(A) & set(B)
    n = len(C)

    if n == 0: 
        ans = "Volunteer cheated!"
    elif n == 1:
        ans = list(C)[0]
    else:
        ans = "Bad magician!"

    print "Case #%d: %s" % (zi, ans)
