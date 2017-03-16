
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

def calc1(m):
    ans = 0
    for i in range(1, len(m)):
        if m[i] < m[i-1]:
            ans += m[i - 1] - m[i]
    return ans


def calc2(m):
    speed = 0
    for i in range(1, len(m)):
        speed = max(speed, m[i - 1] - m[i])

    ans = 0
    for i in range(1, len(m)):
        if m[i-1] < speed:
            ans += m[i-1]
        else:
            ans += speed
    return ans


def calc():
    N = int(get_line())
    s = get_line().split()
    m = [int(i) for i in s]
    return '%s %s' % (calc1(m), calc2(m))


T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
