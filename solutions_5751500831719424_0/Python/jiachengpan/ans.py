#! /usr/bin/python

import sys

def uniq(s):
    result = ""
    resultCnt = []
    l = ""
    acc = 0
    for i in s[:-1]:
        if i != l:
            result += i
            if l:
                resultCnt.append(acc)
                acc = 0
        acc += 1
        l = i
    resultCnt.append(acc)
    return (result, resultCnt)

def solve(strings):
    gold, goldCnt = uniq(strings[0])
    cntCache = [[] for i in range(len(goldCnt))]
    for s in strings:
        ret, retCnt = uniq(s)
        if gold != ret:
            return "Fegla Won"
        i = 0
        for cnt in retCnt:
            cntCache[i].append(cnt)
            i += 1
    result = 0
    for cache in cntCache:
        cache = sorted(cache)
        mid = int(len(cache) / 2)
        for c in cache:
            result += abs(c - cache[mid])
    return str(result)

def main():
    fh = open(sys.argv[1])
    for i in range(int(fh.readline())):
        strings = []
        for j in range(int(fh.readline())):
            strings.append(fh.readline())
        print "Case #%d: %s" % (i + 1, solve(strings))

main()
