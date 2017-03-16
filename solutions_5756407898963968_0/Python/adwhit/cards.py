import sys

path = sys.argv[1]

lines = [line.strip() for line in open(path).readlines()]


nrounds = int(lines[0])
lines = lines[1:]


def make_arr(lines):
    rownum = int(lines[0])
    arr =  [[int(x) for x in line.split()] for line in lines[1:]]
    return (rownum, arr)


def rowset((ind, arr)):
    return set(arr[ind-1])
    
def match(grp1, grp2):
    return grp1 & grp2

def printres(case,s):
    if len(s) == 0:
        print "Case #%d: Volunteer cheated!" % case
    elif len(s) == 1:
        print "Case #%d: %d" % (case, s.pop())
    else:
        print "Case #%d: Bad magician!" % case



rounds = [make_arr(lines[5*x:5*(x+1)]) for x in range(nrounds*2)]

rows = [rowset(grp) for grp in rounds]

matches = [match(rows[2*x],rows[2*x+1]) for x in range(nrounds)]

for (case, s) in enumerate(matches):
    printres(case+1, s)
