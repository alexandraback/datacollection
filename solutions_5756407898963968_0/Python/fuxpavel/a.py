import sys

def get_x_row(s):
    rows = int(s.readline().strip())
    return [s.readline().strip() for i in xrange(4)][rows - 1].split()

def get_case_date(s):
    a1 = get_x_row(s)
    a2 = get_x_row(s)
    return list(set(a1).intersection(set(a2)))


f = open(sys.argv[1])
cases = int(f.readline().strip())

for i in xrange(1, cases + 1):
    result = get_case_date(f)
    if len(result) == 0:
        print "Case #%d: Volunteer cheated!" % i
    if len(result) == 1:
        print "Case #%d: %d" % (i, int(result[0]))
    if len(result) > 1:
        print "Case #%d: Bad magician!" % i
    
