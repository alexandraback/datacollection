import sys
import numpy

BLAH = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

l = sys.stdin.readline()
m = int(l.strip())

for i in range(0, m):
    l = sys.stdin.readline().strip()
    N = int(l)
    l = sys.stdin.readline().strip()
    tokens = l.split(" ")
    p = numpy.array([int(x) for x in tokens])
    sequence = []
    while p.sum() > 0:
        a = numpy.argsort(-p)
#        print(a)
        tp = p[:]
        tp[a[0]] -= 1
        ts = tp.sum()
        tw = numpy.where(tp > ts / 2)[0]
        if tw.shape[0] > 0:
            tp[a[1]] -= 1
            ts = tp.sum()
            tw = numpy.where(tp > ts / 2)[0]
            if tw.shape[0] > 0:
                print("FUCKED")
                break
            sequence.append(BLAH[a[0]] + BLAH[a[1]])
        else:
            sequence.append(BLAH[a[0]])
        p = tp
    print("Case #%d: %s" % (i + 1, " ".join(sequence)))
