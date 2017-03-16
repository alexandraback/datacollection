#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
"""

# import sys
# sys.setrecursionlimit(10000)

impossiburu = "Fegla Won"

def radical(s):
    res = '_'
    for c in s:
        if c != res[-1]:
            res += c
    return res[1:]

def is_impossible(words):
    rad = radical(words[0])
    for word in words:
        if radical(word) != rad:
            return True
    return False

def indx(word):
    w = []
    last = '_'
    for c in word:
        if c != last:
            last = c
            w.append(0)
        w[-1] += 1
    return w

def indxs(words):
    ws = [indx(word) for word in words]
    return ws

def steps(ws, ind, goal):
    cpt = 0
    for w in ws:
        val = w[ind]
        cpt += abs(goal - val)
    return cpt

def brute(ws, ind):
    mini = min(ws, key=lambda x: x[ind])[ind]
    maxi = max(ws, key=lambda x: x[ind])[ind]
    if mini == maxi:
        return 0
    return min((steps(ws, ind, goal) for goal in range(mini, maxi + 1)))

def solve(words):
    if is_impossible(words):
        return impossiburu
    ws = indxs(words)
    res = 0
    for ind, c in enumerate(ws[0]):
        res += brute(ws, ind)
    return res

def main():
    T = int(raw_input())
    for iii in range(1, T + 1):
        N = int(raw_input())
        words = [raw_input() for i in range(N)]
        res = solve(words)
        print "Case #{}: {}".format(iii, res)

def test():
    pass

if __name__ == '__main__':
    # test()
    main()
