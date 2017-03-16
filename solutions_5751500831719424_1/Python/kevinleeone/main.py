import sys
import math

def deduplicate(s):
    ret = ''
    cur = '0'
    curCnt = 0
    cnt = []
    for j in s:
        if j != cur:
            cur = j
            cnt.append(curCnt)
            curCnt = 1
            ret += j
        else:
            curCnt += 1
    cnt.append(curCnt)
    return (ret, cnt[1:])

def solve():
    strNum = int(sys.stdin.readline().split()[0])
    strs = []
    for i in range(strNum):
        strs.append(sys.stdin.readline().strip())
    dedup = list(map(deduplicate, strs))
    first = dedup[0][0]
    for i in range(1, strNum):
        if first != dedup[i][0]:
            return 'Fegla Won'
    total = 0
    for i in zip(*list(zip(*dedup))[1]):
        cur = sorted(i)
        mid = cur[len(cur) // 2]
        for j in i:
            total += abs(j - mid)
    return str(total)

if __name__ == '__main__':
    cases = int(sys.stdin.readline().split()[0])
    for i in range(cases):
        print('Case #%d: %s' % (i + 1, solve()))
