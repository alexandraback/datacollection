#!/usr/bin/env python

import itertools

def canon(word):
    lst = [(k, len(list(g))) for k, g in itertools.groupby(word)]
    canon_word = ''.join([p[0] for p in lst])
    counts = [p[1] for p in lst]
    return (canon_word, counts)

def distance(counts):
    median = sorted(counts)[(len(counts) - 1) / 2]
    return sum([abs(median - count) for count in counts])

def solve(words):
    canon_words = map(canon, words)
    (canon_word, _) = canon_words[0]
    if not all([word == canon_word for (word, _) in canon_words]):
        return None
    counts = [p[1] for p in canon_words]
    return sum(map(distance, zip(*counts)))

T = int(raw_input())
for i in range(T):
    N = int(raw_input())
    words = [raw_input() for j in range(N)]
    ans = solve(words)
    if ans is None:
        print "Case #{}: Fegla Won".format(i + 1)
    else:
        print "Case #{}: {}".format(i + 1, ans)
