from heapq import *

n = input()

for i in xrange(n):
    m = input()
    s = map(int, raw_input().split(" "))

    heap = [(-s[j], chr(j + 65)) for j in xrange(m)]
    count = sum(s)
    heapify(heap)
    print "Case #" + str(i+1) + ":",

    if count % 2 == 1:
        small = heap[0]
        if small[0] < -1:
            new = (small[0] + 1, small[1])
            heapreplace(heap, new)
        else :
            heappop(heap)
        print small[1],
        count -= 1


    while (len(heap) > 0):
        small = heap[0]
        if small[0] < -1:
            new = (small[0] + 1, small[1])
            heapreplace(heap, new)
        else :
            heappop(heap)

        if small[0] * 2 > count:
            raise Exception

        small2 = heap[0]
        if small2[0] < -1:
            new = (small2[0] + 1, small2[1])
            heapreplace(heap, new)
        else :
            heappop(heap)

        print small[1] + small2[1],
        count -= 2

    print