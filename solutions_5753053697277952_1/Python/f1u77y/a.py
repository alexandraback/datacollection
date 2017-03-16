#! /usr/bin/python

def al(i):
    return chr(ord('A') + i)

from queue import PriorityQueue

t = int(input())
for _ in range(1, t + 1):
    n = int(input())
    p = [int(i) for i in input().split()]
    q = PriorityQueue()
    for i, cp in enumerate(p):
        q.put_nowait((-cp, al(i)))

    ans = []
    while not q.empty():
        p1, a = q.get_nowait()
        if q.qsize() % 2 == 0 and p1 == -1:
            ans.append(a)
            continue
        p2, b = q.get_nowait()
        p1, p2 = -p1, -p2
        if p1 - p2 <= 1:
            ans.append(a + b)
            p1 -= 1
            p2 -= 1
        else:
            ans.append(a + a)
            p1 -= 2
        if p1 > 0:
            q.put_nowait((-p1, a))
        if p2 > 0:
            q.put_nowait((-p2, b))
    print("Case #%d: %s" % (_, ' '.join(ans)))
