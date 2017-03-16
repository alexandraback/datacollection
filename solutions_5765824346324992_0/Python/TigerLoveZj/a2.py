#!/usr/bin/env python
# -*- coding: utf-8 -*-


def readint():
    return int(raw_input())


def readarray(f):
    return map(f, raw_input().split())


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
def lcm(a, b):
    return a * b / gcd(a, b)

T = readint()

for t in xrange(T):
    b, n = readarray(int)
    a = readarray(int)
    origA = a[:]
    if n <= b:
        print "Case #%d: %d" % (t+1, n)
    else:
        num = a[0]
        for i, e in enumerate(a):
            if i <= len(a) - 2:
                num = lcm(num, a[i + 1])
        cnt = 0
        for i, e in enumerate(a):
            cnt += num / e
        now = 0
        ans = []
        n = (n - b) % cnt + b + cnt
        #print n
        for i in xrange(n - b):
            if now == 0:
                minA = min(a)
                for j, e in enumerate(a):
                    if e == minA:
                        now += 1
                        ans.append(j)
                        a[j] = origA[j]
                    else:
                        a[j] -= minA
            if i == n - b - 1:
                print "Case #%d: %d" % (t+1, ans[len(ans) - now] + 1)
            now -= 1
            if now == 0:
                ans = []
