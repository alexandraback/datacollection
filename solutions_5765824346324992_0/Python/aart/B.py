#!/usr/bin/python
import sys

#infile = "B-ex.in"
infile = "B-small-attempt4.in"
#infile = "B-large.in"

f    = open( infile )
fout = open( infile.replace("in","out") , "w" )

T = int ( f.readline() )



# http://stackoverflow.com/questions/147515/least-common-multiple-for-3-or-more-numbers

def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""   
    return reduce(lcm, args)

def gcdm(*args):
    """Return lcm of args."""   
    return reduce(gcd, args)


def sim( barbers, N ):

    T = 0

    barbers1 = barbers[:]

    # print 'sim', barbers, "              ", N

    if N == 0 : return 1

    while ( N > 0 ):
        
        # give empty barbers a job

        # print N, barbers

        for i in range(len(barbers)):
        
            if barbers[i] >= 0 :
                barbers[i] = - barbers1[i]
                N -= 1
                if N==0 :
                    print " our guy is " , i+1
                    return i+1
        
        # print N, barbers
        # advance time

        dt = -max(barbers)
                
        for i in range(len(barbers)):
        
            barbers[i] += dt            
            if barbers[i] > 0 : 
                print "error"

    print "error"
    sys.exit()


def solve( barbers, N_ ) :

    #print " sim = ",  sim( barbers[:], N_ )

    print N_, barbers
    T = lcmm( *barbers )
    print "lcm =", T
    print "gcd =", gcdm( *barbers )

    # The situation resets after T minutes
    # how many haircuts in that time?

    NT = sum( T / b for b in barbers )

    print " NT = " , NT

    p = (N_ // NT) -1
    
    N = N_ - p * NT


    return sim( barbers, N )



    
    



for i in range( 1, T+1 ):
    

    B, N = [ int(x) for x in f.readline().split() ]
    barbers = [ int(x) for x in f.readline().split() ]

    ans = solve( barbers, N) 

    
    print "Case #%d: %s" % (i, ans)
    fout.write( "Case #%d: %s\n" % (i, ans))

fout.close()
 
