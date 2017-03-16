import sys
import itertools
import math
import collections
import functools

sys.setrecursionlimit(10000)

def inputInts():
    return map(int, raw_input().split())

def solve(N, coords, n):
    out = 99999999999999999999999999999

    minXPoint = 0
    lowerX = 0
    upperX = 0
    maxX = coords[0][0]
    for i in xrange(1, N):
        if coords[i][0] < coords[minXPoint][0]:
            minXPoint = i
            lowerX = i
            upperX = i
        elif coords[i][0] == coords[minXPoint][0]:
            if coords[i][1] > coords[minXPoint][1]:
                upperX = i
            elif coords[i][1] < coords[minXPoint][1]:
                lowerX = i

        maxX = max(maxX, coords[i][0])

    if coords[n][0] == coords[minXPoint][0] or coords[n][0] == maxX:
        return 0

    # upper side of the polygon
    start = upperX
    while coords[start][0] < maxX:
        alphas = []
        bestAlphaIdx = -1
        for i in xrange(N):
            alphas.append('nope')
            if i == start:
                continue
            if coords[i][0] <= coords[start][0]:
                continue

            alphas[i] = float(coords[i][1] - coords[start][1]) / float(coords[i][0] - coords[start][0])
            if bestAlphaIdx == -1 or alphas[i] > alphas[bestAlphaIdx] or (alphas[i] == alphas[bestAlphaIdx] and coords[i][0] < coords[bestAlphaIdx][0]):
                bestAlphaIdx = i

        if bestAlphaIdx == n:
            return 0
        
        if alphas[n] != 'nope':
            # how many are better than n?
            thisRes = 0
            for al in xrange(N):
                i = alphas[al]
                if i == 'nope':
                    continue
                if i > alphas[n]:
                    thisRes += 1
                elif i == alphas[n] and coords[al][0] < coords[n][0]:
                    thisRes += 1

            out = min(out, thisRes)

        start = bestAlphaIdx

    # Lower side of the polygon
    start = lowerX
    while coords[start][0] < maxX:
        alphas = []
        bestAlphaIdx = -1
        for i in xrange(N):
            alphas.append('nope')
            if i == start:
                continue
            if coords[i][0] <= coords[start][0]:
                continue

            alphas[i] = float(coords[i][1] - coords[start][1]) / float(coords[i][0] - coords[start][0])
            if bestAlphaIdx == -1 or alphas[i] < alphas[bestAlphaIdx] or (alphas[i] == alphas[bestAlphaIdx] and coords[i][0] < coords[bestAlphaIdx][0]):
                bestAlphaIdx = i

        if bestAlphaIdx == n:
            return 0
        
        if alphas[n] != 'nope':
            # how many are better than n?
            thisRes = 0
            for al in xrange(N):
                i = alphas[al]
                if i == 'nope':
                    continue
                if i < alphas[n]:
                    thisRes += 1
                elif i == alphas[n] and coords[al][0] < coords[n][0]:
                    thisRes += 1

            out = min(out, thisRes)

        start = bestAlphaIdx

    # Just remove minX
    lesserX = 0
    for i in xrange(N):
        if coords[i][0] < coords[n][0]:
            lesserX += 1
    out = min(out, lesserX)

    # Just remove maxX
    lesserX = 0
    for i in xrange(N):
        if coords[i][0] > coords[n][0]:
            lesserX += 1
    out = min(out, lesserX)

    return out

T = int(raw_input())
for testId in range(T):
    N = input()
    coords = []
    for n in xrange(N):
        coords.append(inputInts())

    print "Case #{:d}:".format(testId+1)
    for n in xrange(N):
        print solve(N, coords, n)

