#!/usr/bin/env python


def read():
    raw_input()
    return map(int, raw_input().split())


def work(cases, vList):
    ans = ''
    
    while sum(vList) > 0:
        maxV = 0
        maxIdx = []
        
        for (idx, v) in enumerate(vList):
            if maxV < v:
                maxV = v
                maxIdx = [idx]
            elif maxV == v:
                maxIdx.append(idx)

        ans += ' '
        
        if len(maxIdx) == 2:
            for idx in maxIdx:
                ans += chr(ord('A') + idx)
                vList[idx] -= 1
        else:
            ans += chr(ord('A') + maxIdx[0])
            vList[maxIdx[0]] -= 1
    
    print "Case #%d:%s" % (cases, ans)


if __name__ == "__main__":
    for i in range(int(raw_input())):
        work(i + 1, read())
