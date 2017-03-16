#!/usr/bin/env python

from __future__ import print_function

def extractPattern(s):
    pat = [s[0]]
    for i in xrange(1, len(s)):
        if s[i] != pat[-1]:
            pat.append(s[i])
    return ''.join(pat)

def extractCounts(s, pat):
    counts = []
    i = 0
    for c in pat:
        j = i
        while j < len(s) and s[j] == c:
            j += 1
        counts.append(j - i)
        i = j
    return counts

def minSegmentSteps(counts):
    counts.sort()
    sums = [0]
    for n in counts:
        sums.append(sums[-1] + n)
    sum = sums[-1]
    best = 99999999 # approximately infinity
    for tgtIdx in xrange(len(counts)):
        steps = counts[tgtIdx] * (2*tgtIdx - len(counts) + 1)
        steps += sum - sums[tgtIdx+1] - sums[tgtIdx]
        best = min(best, steps)
    return best

def readSolveCase():
    N = int(raw_input())
    s1 = raw_input()
    pattern = extractPattern(s1)
    countss = [extractCounts(s1, pattern)]
    wrong = False
    for n in xrange(1, N):
        s = raw_input()
        if extractPattern(s) != pattern:
            wrong = True
        countss.append(extractCounts(s, pattern))
    if wrong:
        return None
    minSteps = 0
    for i in xrange(len(pattern)):
        minSteps += minSegmentSteps([counts[i] for counts in countss])
    return minSteps

def main():
    T = int(raw_input())
    for t in xrange(1, T+1):
        result = readSolveCase()
        print('Case #{}: {}'.format(t, 
                                    result if result != None else "Fegla Won"))

if __name__ == "__main__":
    main()
