for case in range(input()):
    print "Case #%s:" % (case+1),
    R, C, N = map(int, raw_input().split())
    odd = R % 2 == 1 and C % 2 == 1
    half = R*C/2 + odd #((R+1)/2) * ((C+1)/2)
    if N <= half:
        print 0
        #print R, C, N, half
    elif N <= half + odd:
        if R == 1 or C == 1:
            print 2
        else:
            print 3
        #print "odd",
        #print R, C, N, half
    else:
        degrees = [0, 0, 0, 0, 0]
        if R == 1 or C == 1:
            degrees[1] = int(odd)
            degrees[2] = half - odd
        elif odd:
            degrees[2] = 4
            degrees[3] = 2*(R/2) + 2*(C/2) - 4
        else:
            degrees[2] = 2
            oneodd = R % 2 == 1 or C % 2 == 1
            degrees[3] = 2*(R/2) + 2*(C/2) - 2 + oneodd - degrees[2]
        degrees[4] = half - sum(degrees)
        cumsum = [sum(degrees[i:]) for i in xrange(len(degrees))]
        total = 2*R*C - R - C
        rem = R*C - N
        #print R,C,N,total,degrees, cumsum, rem,
        if rem <= cumsum[4]:
            print total-4*rem
        elif rem <= cumsum[3]:
            print total-4*degrees[4]-3*(rem-cumsum[4])
        elif rem <= cumsum[2]:
            print total-4*degrees[4]-3*degrees[3]-2*(rem-cumsum[3])
        else:
            print total-4*degrees[4]-3*degrees[3]-2*degrees[2]-1*(rem-cumsum[3])
