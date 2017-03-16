import sys

f = open(sys.argv[1])
n = int(f.readline())


for t in xrange(1,n+1):
    f.readline()
    s = [ int(x) for x in f.readline().strip("\n").split(" ") ]
    dropsum = 0
    maxdrop = 0
    mdsum = 0
    for i in xrange(1,len(s)):
        if s[i] < s[i-1]:
            dropsum += s[i-1] - s[i]
            if s[i-1] - s[i] > maxdrop:
                maxdrop = s[i-1] - s[i]
    for i in xrange(1,len(s)):
        mdsum += min(maxdrop, s[i-1])
    
    
    print "Case #%d: %d %d" % (t,dropsum, mdsum)



        










