from itertools import count
from random import randint
from sys import stdout

namein = 'A-small-attempt0.in'
nameout = 'a-small.out'

def solve():
    N = int(fin.readline())
    left = [int(s) for s in fin.readline().split()]
    total = sum(left)
    ret = []
    def dfs():
        nonlocal ret
        nonlocal left
        nonlocal total
        if total == 0:
            return True
        else:
            ma1 = max(range(N), key=lambda i:left[i])
            if left[ma1]*2 > total:
                return False
            tmp = left[ma1]
            left[ma1] = 0
            ma2 = max(range(N), key=lambda i:left[i])
            left[ma1] = tmp
            if left[ma1] >= 2:
                left[ma1] -= 2
                total -= 2
                if dfs():
                    ret.append([ma1, ma1])
                    return True
                left[ma1] += 2
                total += 2
            if left[ma1] >= 1 and left[ma2] >= 1:
                left[ma1] -= 1
                left[ma2] -= 1
                total -= 2
                if dfs():
                    ret.append([ma1, ma2])
                    return True
                left[ma1] += 1
                left[ma2] += 1
                total += 2
            left[ma1] -= 1
            total -= 1
            if dfs():
                ret.append([ma1])
                return True
            total += 1
            left[ma1] += 1
            return False
    dfs()
    ret2 = []
    for r in reversed(ret):
        s = ''
        for rr in r:
            s += chr(ord('A')+rr)
        ret2.append(s)
    return ' '.join(ret2)

fin = open(namein, 'r')
fout = open(nameout, 'w')
# fout = stdout
T = int(fin.readline())
for i in range(1, T+1):
    print('Case #{}: {}'.format(i, solve()), file=fout)
