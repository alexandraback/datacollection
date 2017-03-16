#!/usr/bin/python

from __future__ import division
from gcj import *

# boolean flags, reachable via OPTS.flagname. Space separated in string
FLAGS = 'slow'

def case():
    R, C, N = ints()
    if R < C:
        C, R = R, C
    assert C <= R

    if OPTS.slow:
        return slow(R,C,N)

    maxok = (R*C+1) // 2
    if N <= maxok:
        return 0

    toremove = R*C - N
    if C == 1:
        return (R-1) - toremove*2
    else:
        hoeken = 4
        randen = (R-2)*2 + (C-2)*2
        mid = R*C - hoeken - randen

    assert mid >= 0
    assert randen >= 0

    print 'h=%d, r=%d, m=%d' % (hoeken, randen, mid)

    best = 1e12
    for midbias in [0, 1]:
        toremove = R*C - N
        winst = 0

        maxmid = (mid+midbias) // 2 
        inmid = min(maxmid, toremove)
        print 'inmid', inmid
        toremove -= inmid
        winst += inmid*4

        maxrand = randen // 2
        if R%2 == 1 and C%2 == 1:
            if midbias:
                maxrand -= 2
            else:
                maxrand += 2
        inrand = min(maxrand, toremove)
        print 'inrand', inrand
        toremove -= inrand
        winst += inrand*3

        if R%2 == 1 and C%2 == 1:
            if midbias:
                maxhoek = hoeken
            else:
                maxhoek = 0
        else:
            maxhoek = hoeken // 2

        inhoek = min(maxhoek, toremove)
        print 'inhoek', inhoek
        toremove -= inhoek
        winst += inhoek * 2

        alleranden = (R-1) * C + (C-1) * R

        print 'all, winst', alleranden, winst

        sol = alleranden - winst
        if sol < best:
            best = sol

    return best

def slow(R,C,N):
    #assert C <= R
    best = 1e12
    for i in xrange(2**(R*C)):
        unh = 0
        if sum(map(int, bin(i)[2:])) != N: continue
        for r in range(R):
            for c in range(C-1):
                setje = (i >> (r*C + c)) & 3
                if setje == 3: unh += 1
        for c in range(C):
            for r in range(R-1):
                b1 = c + r*C
                b2 = b1 + C
                if ((i >> b1) & 1) and ((i >> b2) & 1):
                    unh += 1
        if unh < best:
            best = unh
            bestsol = i

    for r in range(R):
        for c in range(C):
            b1 = c + r*C
            char = ' x'[(bestsol>>b1) & 1]
            sys.stdout.write(char)
        print

    return best

def printslow(*a):
    R,C,N = map(int, a)
    print slow(R,C,N)

if __name__ == '__main__':
    main()
