import sys

f = open(sys.argv[1])
n = int(f.readline())

for t in xrange(1,n+1):
    s = int(f.readline().strip("\n"))
    print "Case #%d:" % t
    points = []
    for i in xrange(s):
        p = f.readline().strip("\n").split(" ")
        points.append((int(p[0]),int(p[1])))

    for i in xrange(len(points)):
        g0 = 0
        g1 = 0
        l0 = 0
        l1 = 0
        for j in xrange(len(points)):
            if i==j:
                continue
            if points[j][0] > points[i][0]:
                g0 += 1
            if points[j][0] < points[i][0]:
                l0 += 1
            if points[j][1] > points[i][1]:
                g1 += 1
            if points[j][1] < points[i][1]:
                l1 += 1
        #print points[i]
        #print g0
        #print l0
        #print g1
        #print l1
        m = min(g0, l0, g1, l1)
        if m == 2:
            print 1
        elif m == 1:
            print 0
        else:
            print m






    
    
    
    
    
    #print "Case #%d: %d" % (t,maxd)



        










