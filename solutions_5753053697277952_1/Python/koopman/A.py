import sys
from Queue import PriorityQueue

inf = sys.argv[1]

f = open(inf, 'rU')
outf = open(inf + ".out", 'w')

T = int(f.readline())
for t in xrange(T):

    N = int(f.readline().strip())
    counts = [int(x) for x in f.readline().strip().split()]

    q = PriorityQueue()
    for i, c in enumerate(counts):
        q.put((-c, chr(ord('A') + i)))
    total = sum(counts)

    result = ""
    while not q.empty():
        first = q.get()
        result += first[1]
        total -= 1
        first = (first[0] + 1, first[1])
        if first[0] < 0:
            q.put(first)

        if not q.empty() and total != 2:
            second = q.get()
            result += second[1]
            total -= 1
            second = (second[0] + 1, second[1])
            if second[0] < 0:
                q.put(second)
        result += " "

    outf.write("Case #{0}: {1}\n".format(t+1, result.strip()))

f.close()
outf.close()
