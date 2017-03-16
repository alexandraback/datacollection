#!/usr/bin/python

#infile = "A-ex.in"
infile = "A-small-attempt0.in"
#infile = "A-large.in"

f    = open( infile )
fout = open( infile.replace("in","out") , "w" )

T = int ( f.readline() )

def solve( m ):

    maxr = 0
    a1,a2 = 0,0
    
    for i in range( len(m) -1 ):

        a,b = m[i], m[i+1]
        
        if b<a :
            r = a-b
            if r> maxr : maxr = r
            a1 +=r

    for s in m[:-1] :
        # eat maxr, unless there are fewer available
        a2 += min( s, maxr )
        

    return str(a1)+" " + str(a2)
        

for i in range( 1, T+1 ):
    
    N = [f.readline().split()]
    m = [ int(x) for x in f.readline().split() ]
    
    ans = solve( m )

    
    
    print "Case #%d: %s" % (i, ans)
    fout.write( "Case #%d: %s\n" % (i, ans))

fout.close()
 
