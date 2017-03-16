#!/usr/bin/env python
import itertools
class END(Exception):
    pass

def parse_str(s):
    prev = 0
    count = 0
    result = []
    for c in s:
        if prev != c:
            if prev != 0:
                result.append((prev, count))
                count = 0
        prev = c
        count += 1
    result.append([prev, count])
    return result

def get_roots(r):
    return tuple([l[0] for l in r])

def all_equal(l):
    for i in range(len(l)-1):
        if (l[i] != l[i+1]):
            return False
    return True

def tekazu(l):
    mymin = 1e9;
    for i in range(min(l), max(l)+1):
        mysum = sum([abs(i - ll) for ll in l])
        mymin = min(mysum, mymin)
    return mymin

T = int(input())
for i in range(T):
    N = input()
    strs = []
    result = 0
    for j in range(N):
        strs.append(parse_str(raw_input()))
    try:
        if not all_equal([get_roots(j) for j in strs]):
            result = 'Fegla Won'
            raise END
        for j in range(len(strs[0])):
            result += tekazu([k[j][1] for k in strs])
    except END:
        pass

    print 'Case #%d:' % (i+1), result
