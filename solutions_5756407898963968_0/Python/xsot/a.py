for TC in range(1, int(raw_input()) + 1):
    a = b = {}
    row = int(raw_input())
    for i in range(4):
        line = raw_input()
        if row == i+1:
            a = set(line.split())
    
    row = int(raw_input())
    for i in range(4):
        line = raw_input()
        if row == i+1:
            b = set(line.split())
            
    result = a & b
    if len(result) == 1:
        print "Case #%d: %s" % (TC, list(result)[0])
    elif len(result) > 1:
        print "Case #%d: Bad magician!" % TC
    else:
        print "Case #%d: Volunteer cheated!" % TC