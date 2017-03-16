#!/usr/bin/env python


def read():
    nB, nPpl = map(int, raw_input().split())
    vList = map(int, raw_input().split())
    return vList, nPpl


def work(cases, (vList, N)):
    L = 0
    R = max(vList) * N
    
    while L < R:
        mid = (L + R) / 2
        
        def calc(t):
            ret = 0
            for i in range(len(vList)):
                ret += (t + vList[i] - 1) / vList[i]
            return ret

        if N <= calc(mid):
            R = mid
        else:
            L = mid + 1

    L -= 1
    
    total = 0
    for i in range(len(vList)):
        total += (L + vList[i] - 1) / vList[i]
    
    for i in range(len(vList)):
        if L % vList[i] == 0:
            total += 1
            if total == N:
                print "Case #%d: %d" % (cases, i + 1)
                break


if __name__ == "__main__":
    for i in range(int(raw_input())):
        work(i + 1, read())
