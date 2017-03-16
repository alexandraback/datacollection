#/usr/bin/env python2.7
#-*- coding:utf-8 -*-
#huanghaiping2@gmail.com
# vim: ts=4 sts=4 sw=4 et

import sys
from multiprocessing import Process, Queue

def readline():
    return sys.stdin.readline().strip()

def checkNotPossible(charDicts):
    globalKeys = set()
    for charDict in charDicts:
        for k in charDict:
            globalKeys.add(k)

    for charDict in charDicts:
        for k in globalKeys:
            if k not in charDict:
                return False

    return True

def getPiece(string, startPos):
    if startPos >= len(string):
        return (0, None)
    lastChar = None
    lenCount = 0
    piece = []
    for i in xrange(startPos, len(string)):
        char = string[i]
        if lastChar is None:
            lastChar = char
        elif char != lastChar:
            return (lenCount, ''.join(piece))
        piece.append(char)
        lenCount += 1

    return (lenCount, ''.join(piece))

def leastAction(pieces):
    keyWord = None
    for piece in pieces:
        if piece is None:
            continue
        keyWord = piece[0]
        break

    if keyWord is None:
        return -2
    for piece in pieces:
        if piece is None or keyWord != piece[0]:
            return -1

    minCount = sys.maxint
    N = len(pieces)
    for n in xrange(N):
        bench = pieces[n]
        count = 0
        for i in xrange(N):
            if i == n:
                continue
            count += abs(len(bench) - len(pieces[i]))
        if count < minCount:
            minCount = count

    return minCount


def solve(inQueue, outQueue):
    while True:
        paramDict = inQueue.get()
        if paramDict is None:
            return
        N = paramDict['N']
        strings = paramDict['strings']

        posInfo = [0 for n in xrange(N)]
        minActions = 0
        while True:
            pieces = []
            for idx, string in enumerate(strings):
                lenCount, piece = getPiece(string, posInfo[idx])
                pieces.append(piece)
                posInfo[idx] += lenCount
            ret = leastAction(pieces)
            if ret == -1:
                minActions = sys.maxint
                break
            elif ret == -2:
                break
            minActions += ret
        if minActions == sys.maxint:
            outQueue.put((paramDict['T'], 'Fegla Won'))
        else:
            outQueue.put((paramDict['T'], minActions))


if __name__ == '__main__':
    PROCNUM = 1

    procs = []
    inQueue = Queue()
    outQueue = Queue()

    T = int(readline())
    for t in xrange(T):
        N = int(readline())
        strings = []
        for n in xrange(N):
            strings.append(readline())
        paramDict = {}
        paramDict['T'] = t+1
        paramDict['N'] = N
        paramDict['strings'] = strings
        inQueue.put(paramDict)

    for i in xrange(PROCNUM):
        inQueue.put(None)

    if PROCNUM > 1:
        for i in xrange(PROCNUM):
            p = Process(target=solve, args=(inQueue, outQueue))
            p.start()

        for i in xrange(PROCNUM):
            p.join()
    else:
        solve(inQueue, outQueue)

    results = []
    for t in xrange(T):
        result = outQueue.get()
        results.append(result)
    results.sort(key=lambda x:x[0])
    for result in results:
        print 'Case #%s: %s' % (result[0], result[1])

