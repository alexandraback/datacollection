import sys, math

stdin = sys.stdin.readlines()
cases = int(stdin.pop(0))
for case in xrange(cases):
    stdin.pop(0)
    mushrooms = stdin.pop(0).split(' ')
    for i in xrange(len(mushrooms)):
        mushrooms[i] = int(mushrooms[i])
    largestdiff = 0
    smallestdiff = 0
    for i in xrange(1,len(mushrooms)):
        diff = mushrooms[i-1] - mushrooms[i]
        if diff > largestdiff:
            largestdiff = diff
        if diff >= 0:
            smallestdiff += diff
    emptyplate = 0
    for i in xrange(len(mushrooms)-1):
        if largestdiff > mushrooms[i]:
            emptyplate += mushrooms[i]
        else:
            emptyplate += largestdiff
    print "Case #"+str(case+1)+":", smallestdiff, emptyplate
