import sys

f = open(sys.argv[1])
n = int(f.readline())

def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

for t in xrange(1,n+1):
    posinline = int(f.readline().strip("\n").split(" ")[1])
    barbertimes = [ int(x) for x in f.readline().strip("\n").split(" ") ]
    mintime = min(barbertimes) 
    #print barbertimes
    #print "posinline:" + str(posinline)
    if posinline < len(barbertimes):
        print "Case #%d: %d" % (t,posinline)
        continue
    
    sl = sorted(barbertimes)
    if sl[0] == sl[-1]:
        foo = posinline % len(sl)
        if foo == 0:
            foo = len(sl)
        print "Case #%d: %d" % (t, foo)
        continue 

    summ = 0
    kgv = 1
    for x in barbertimes:
        kgv = lcm(kgv,x)

    #print "kgv:" + str(kgv)

    for x in barbertimes:
        summ += (kgv / x)

    #print "summ:" + str(summ)

    if posinline > summ:
        posinline = posinline % summ
        if posinline == 0:
            posinline = summ 
        #print "Case #%d: %d" % (t, len(sl))
        #continue 
    
    #print "reduced pos in line:" + str(posinline)

    

    time = 0
    while posinline > 0:
        for i in xrange(len(barbertimes)):
            if time == 0 or (time % barbertimes[i]) == 0:
                if posinline == 1:
                    print "Case #%d: %d" % (t,i+1)
                posinline -= 1
        time += 1
     #   print "t: %d" % time
     #   print "p: %d" % posinline

    #for i in xrange(len(barbertimes)):
    #    if time % barbertimes[i]  == 0:
    ##        print i+1
            

    #barbertimeswithpos = []
    #for x in xrange(len(barbertimes)):
    #    barbertimeswithpos.append((x+1, barbertimes[x]))

    #sbt = sorted(barbertimeswithpos, key=lambda x: x[1])
    
    #print sbt[(posinline % len(sbt))-1]
    
    
    
    
    
    #print "Case #%d: %d" % (t,maxd)



        










