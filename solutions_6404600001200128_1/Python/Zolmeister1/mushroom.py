import sys
import math

inName = sys.argv[1]
outName = inName[:inName.index('.')] + '.out'

fin = open(inName)
fout = open(outName, 'w')

cases = int(fin.readline())

def pp(case, out):
    ss= "Case #%d: %s\n" % (case+1, out)
    print ss,
    fout.write(ss)



for case in xrange(cases):
    N = int(fin.readline().strip())
    stack = map(int, fin.readline().strip().split(' '))

    # any number at any time
    totalFirst = 0
    last = stack[0]
    for count in stack[1:]:
        totalFirst += max(last - count, 0)
        last = count

    minRate = 0
    last = stack[0]
    for count in stack[1:]:
        minRate = max(last - count, minRate)
        last = count

    totalSecond = 0
    last = stack[0]
    for count in stack[1:]:
        if last >= minRate:
            totalSecond += minRate
        else:
            totalSecond += last
        last = count

    #print totalFirst
    pp(case, str(totalFirst) + ' ' + str(totalSecond))

fout.close()
