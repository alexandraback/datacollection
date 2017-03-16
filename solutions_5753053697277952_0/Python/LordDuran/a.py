# from __future__ import division
from pprint import pprint
import time
inputfile = file("in", "rb")
outputfile = file("out", "wb")
out_s = "Case #%d: %s"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]
parse_linef = lambda: [float(a) for a in inputfile.readline().split()]
rl = lambda: inputfile.readline().replace("\n","")
INF = 10**9

UPS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def do_case(ncase):
    N, = parse_line()
    sen_count = parse_line()
    steps = []

    if N == 2:
        # no party has majority so both are ==
        print >>outputfile, out_s % (ncase, str('AB ' * sen_count[0]).strip())
        return

    while max(sen_count) > 0:
        print sen_count
        maxi = 0
        maxv = sen_count[0]
        for i in xrange(1, len(sen_count)):
            if maxv < sen_count[i]:
                maxv = sen_count[i]
                maxi = i

        first = maxi
        sen_count[maxi] -= 1

        maxi = 0
        maxv = sen_count[0]
        for i in xrange(1, len(sen_count)):
            if maxv < sen_count[i]:
                maxv = sen_count[i]
                maxi = i

        second = maxi
        sen_count[maxi] -= 1
        if maxv > 0:
            steps.append(UPS[first] + UPS[second])
        else:
            steps.append(UPS[first])

    if len(steps[-1]) == 1:
        steps[-1], steps[-2] = steps[-2], steps[-1]
    print >>outputfile, out_s % (ncase, str(' '.join(steps)))

start_time = time.time()
T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    print "Doing case", ncase
    do_case(ncase)
    print "Done, time", time.time()-start_time
    
