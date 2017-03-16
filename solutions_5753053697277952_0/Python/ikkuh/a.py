T = input()

for i in range(1, T+1):
    N = input()
    P = map(int, raw_input().split())

    print "Case #%d:" % i,

    while max(P) > 0:
        index1 = P.index(max(P))
        P[index1] -= 1

        if max(P) != 0 and sum(P) != 2:
            index2 = P.index(max(P))
            P[index2] -= 1
            print "%c%c" % (chr(index1+65), chr(index2+65)),
        else:
            print "%c" % chr(index1+65),
    print

