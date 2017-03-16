#!/usr/bin/python

from __future__ import division

import sys, os, subprocess, time, ctypes

def line():
    return sys.stdin.readline().strip()

def doit():
    N = int(line())
    for i in range(N):
        print 'Case #%d:' % (i+1),
        res = go()
        print res

def go():
    N = int(line())
    S = [line() for i in range(N)]

    theletters = None
    allcounts = []
    for s in S:
        letters = []
        counts = []
        for c in s:
            if not letters or c != letters[-1]:
                letters.append(c)
                counts.append(1)
            else:
                counts[-1] += 1
        if theletters is None:
            theletters = letters
        else:
            if theletters != letters:
                return 'Fegla Won'
        allcounts.append(counts)

    steps = 0
    for C in zip(*allcounts):
        best = 1e100
        for i in range(1, 101):
            now = sum(abs(i-c) for c in C)
            if now < best:
                best = now
        steps += best

    return steps

def compileIfNeeded():
    letter, _, _ = os.path.basename(sys.argv[0]).partition('.')
    cpp = '%s.cpp' % letter
    if os.path.exists(cpp):
        print 'Compling...'
        subprocess.check_call('g++ -Wall -g -O3 -fPIC %s -shared -o lib.so' % cpp,
            shell=True)

def main():
    if len(sys.argv) > 1:
        return doit()

    compileIfNeeded()

    files = []
    for fn in os.listdir('.'):
        if fn.endswith('.in'):
            files.append((os.path.getmtime(fn), fn))
    fn = max(files)[1]

    root = fn[:-2]
    with open(fn) as fdin:
      with open(root+'result', 'wb') as fdout:
        start = time.time()
        print 'Running...'
        subprocess.check_call([__file__, 'doit'],
                stdin=fdin,
                stdout=fdout)
        print 'Done in %.3fs' % (time.time()-start)
    print 'Diffing...'
    subprocess.call(['diff', '-sdu', root+'out', root+'result'])

if __name__ == '__main__':
    main()
