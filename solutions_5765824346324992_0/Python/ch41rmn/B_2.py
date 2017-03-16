#/usr/bin/env python

import sys, os
from math import ceil
from operator import itemgetter

def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

# the first line is the total number of cases
cases_total = int(sys.stdin.readline().strip())

case = 0                                # id of the case
while case < cases_total:
    case += 1                           # iterate case id

    # do your input here
    [ B, N ] = [ int(x) for x in sys.stdin.readline().strip().split() ]
    Mk = [ int(x) for x in sys.stdin.readline().strip().split() ]


    # Let Bk be the progress each barber is through their current client
    # and let Nk be the number of clients each barber has finished
    # then:
    #      Mk * Nk + Bk = L must be constant for all barbers
    # subject to the constraint that Bk<Mk, and Sum Nk = N-1

    if N > B:
        Nk = [0]*B
        tstep = min(Mk)
        Lmin = 0
        Lmax = tstep*N
        finish = False
        while not(finish):
            Lguess = (Lmin+Lmax)//2
            for i in range(B):
                Nk[i] = Lguess // Mk[i]
            NN = sum(Nk)
            if NN > N-B-1:
                Lmax = Lguess
            elif NN < N - 2*B:
                Lmin = Lguess
            else:
                L = Lguess
                finish = True
            if Lmax-Lmin==1:
                L = Lmin
                finish = True
    else:
        NN = 0
        L = 0
    # we have some estimate of L that places us near when we are at the queue
    #print N, NN, L
    N = N - NN
    #print N, Mk
    Bk = [0]*B
    iBk = [0]*B
    for i in range(B):
        Bk[i] = L % Mk[i]
        if Bk[i]!=0:
            N = N - 1
            iBk[i] = Mk[i] - Bk[i]
    #print N, Bk
    #print N, iBk

    while N>1:
        (i,m) = min(enumerate(iBk),key=itemgetter(1))
        iBk = [ b - m for b in iBk ]
        iBk[i] = Mk[i]
        N = N - 1 
        #print N, iBk

    # we are now in queue position 1
    (i,m) = min(enumerate(iBk),key=itemgetter(1))
    out = i+1
        

    # set your output here
    out = str(out)

    print "Case #"+str(case)+": "+out   # the output format is 'Case #${case}: ${output}'
