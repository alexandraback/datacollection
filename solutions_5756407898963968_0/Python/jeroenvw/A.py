#!/usr/bin/python

import os

def line():
    return FD.readline().strip()

def doit():
    N = int(line())
    for i in range(N):
        go(i)

def go(testcasenr):
    opts = [None]*2
    for i in range(2):
        row = int(line())
        rows = [line().split() for _ in range(4)]
        opts[i] = rows[row-1]
    a,b = opts
    pos = set(a) & set(b)
    if len(pos) == 1:
        ans, = pos
    elif len(pos) > 1:
        ans = 'Bad magician!'
    else:
        ans = 'Volunteer cheated!'
    print 'Case #%d: %s' % (testcasenr+1, ans)

def main():
    files = []
    for fn in os.listdir('.'):
        if fn.endswith('.in'):
            files.append((os.path.getmtime(fn), fn))
    fn = max(files)[1]
    with open(fn) as fd:
        global FD
        FD = fd
        doit()

if __name__ == '__main__':
    main()
