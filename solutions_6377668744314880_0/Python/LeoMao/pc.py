#! /usr/bin/env python

class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __repr__(self):
        return "({}, {})".format(self.x, self.y)

    def __eq__(self, p):
        return self.x == p.x and self.y == p.y
    
def cross(p, p1, p2):
    return (p1.x - p.x) * (p2.y - p.y) - (p1.y - p.y) * (p2.x - p.x)

def find_less(p, ps):
    ans = len(ps)
    for p1 in ps:
        if p1 == p:
            continue
        pcnt = 0
        ncnt = 0
        for p2 in ps:
            if p2 == p or p2 == p1:
                continue
            c = cross(p, p1, p2)
            if c > 0:
                pcnt += 1
            elif c < 0:
                ncnt += 1
        ans = min(ans, pcnt, ncnt)
    return ans

T = int(input())

for t in range(1, T+1):
    n = int(input())
    ps = []
    for i in range(n):
        x, y = [int(a) for a in input().split()]
        ps.append(Point(x, y))

    logs = []
    for p in ps:
        logs.append(find_less(p, ps))

    print("Case #{}:".format(t))
    for l in logs:
        print(l)
