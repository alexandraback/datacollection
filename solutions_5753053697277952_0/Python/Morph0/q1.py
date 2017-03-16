from progressbar import *
from heapq import *

PB_WIDGETS = [Percentage(), ' | ', SimpleProgress(), ' ', Bar(), ' ', Timer(), ' ', ETA()]


def solve(P):
    result = ""
    P = [(-c, chr(p + ord('A'))) for p, c in enumerate(P)]
    heapify(P)
    while P:
        if len(P) == 2 and P[0][0] == P[1][0]:
            c1, p1 = heappop(P)
            c2, p2 = heappop(P)
            result += "%c%c " % (p1, p2)
            if c1 < -1:
                heappush(P, (c1 + 1, p1))
                heappush(P, (c2 + 1, p2))
        else:
            c, p = heappop(P)
            if c < -1:
                heappush(P, (c+1, p))
            result += "%c " % p
    return result.strip()


with open("q1.in") as fin:
    T = int(fin.readline())
    output = ""
    pb = ProgressBar(widgets=PB_WIDGETS, maxval=T, fd=sys.stdout).start()
    for t in xrange(T):
        pb.update(t)
        print ""
        fin.readline()
        P = map(int, fin.readline().split())
        output += "Case #%d: %s\n" % (t+1, solve(P))
    with open('q1.out', 'w') as fout:
        fout.write(output)