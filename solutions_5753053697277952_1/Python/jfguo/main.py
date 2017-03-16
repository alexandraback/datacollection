
import os
import sys
import glob
import subprocess
import random
import fileinput


next_line = 0
lines = [line.strip() for line in fileinput.input()]
def get_line():
    global next_line
    i = next_line
    next_line += 1
    return lines[i]


def calc():
    N = int(get_line())
    s = get_line().split()
    ps = []
    for i in range(len(s)):
        ps.append([int(s[i]), i])

    res = []
    while True:
        ps = [i for i in ps if i[0] != 0]
        if not ps:
            break
        ps = sorted(ps)

        #print ps
        
        while ps[-1][0] > ps[-2][0]:
            res.append(chr(ord('A') + ps[-1][1]))
            ps[-1][0] -= 1

        if ps[-1][0] == 1 and len(ps) > 2:
            res.append(chr(ord('A') + ps[-1][1]))
            ps[-1][0] -= 1
        else:
            res.append(chr(ord('A') + ps[-1][1]) + chr(ord('A') + ps[-2][1]))
            ps[-1][0] -= 1
            ps[-2][0] -= 1

    return ' '.join(res)


T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
