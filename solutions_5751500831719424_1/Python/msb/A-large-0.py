#!/usr/bin/env python

def solve(words):
    canwords = []
    countwords = []
    for word in words:
        counts = []
        chars = ""
        prev = ""
        for c in word:
            if c != prev:
                chars += c
                prev = c
                counts.append(0)
            counts[-1] += 1
        countwords.append(counts)
        canwords.append(chars)
    theword = canwords[0]
    for word in canwords[1:]:
        if word != theword:
            print "Fegla Won"
            return
    acc = 0
    i = 0
    for c in theword:
        min = 101
        max = 0
        for counts in countwords:
            if counts[i] < min:
                min = counts[i]
            if counts[i] > max:
                max = counts[i]
        acc += max - min
        i += 1
    print acc

for case in xrange(int(raw_input())):
    print "Case #%d:" % (case+1),
    num_words = int(raw_input())
    words = []
    for i in xrange(num_words):
        words.append(raw_input())
    solve(words)
