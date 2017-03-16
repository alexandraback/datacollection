
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

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def calc():
    parts = get_line().split()
    B = int(parts[0])
    N = int(parts[1])
    parts = get_line().split()
    m = [int(i) for i in parts]

    T = 1
    for i in m:
        T *= i

    t = 0
    for i in m:
        t += T / i

    N = (N - 1) % t

    a = []
    for i in range(B):
        a.extend([(j * m[i], i) for j in range(T/m[i])])

    a.sort()
    return a[N][1] + 1

    """
    l = 0
    h = T
    while l < h:
        mi = (l + h) / 2
        num = 0
        for i in range(B):
            num += mi / m[i] + 1
        if num < N + 1:
            l = mi + 1
        else:
            h = mi

    for i in range(B):
        if h % m[i] == i:
            return i + 1
    """


T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
