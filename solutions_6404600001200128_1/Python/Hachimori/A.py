#!/usr/bin/env python


def read():
    raw_input()
    return map(int, raw_input().split())


def work(cases, vList):
    ans1 = 0
    ans2 = 0

    for i in range(len(vList) - 1):
        if vList[i] > vList[i + 1]:
            ans1 += vList[i] - vList[i + 1]

    maxV = 0
    for i in range(len(vList) - 1):
        maxV = max(maxV, vList[i] - vList[i + 1])
    
    for i in range(len(vList) - 1):
        ans2 += min(maxV, vList[i])
    
    print "Case #%d: %d %d" % (cases, ans1, ans2)


if __name__ == "__main__":
    for i in range(int(raw_input())):
        work(i + 1, read())
