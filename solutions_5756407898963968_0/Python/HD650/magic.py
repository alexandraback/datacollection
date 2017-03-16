import sys, math

infile = sys.stdin

T = int(infile.readline())

for case_num in xrange(1, T+1):

    r = int(infile.readline()) - 1
    for i in xrange(4):
        line = [int(v) for v in infile.readline().split()]
        if i == r:
            first = set(line)
    r = int(infile.readline()) - 1
    for i in xrange(4):
        line = [int(v) for v in infile.readline().split()]
        if i == r:
            second = set(line)

    ret = first & second
    if len(ret) == 0:
        print "Case #%d: Volunteer cheated!" % case_num        
    elif len(ret) > 1:
        print "Case #%d: Bad magician!" % case_num
    else:
        print "Case #%d: %d" % (case_num, ret.pop())
