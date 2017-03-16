#!/usr/bin/env python
# -*- coding: utf-8 -*-

def solve(n, m):
	m = map(int, m.split())
	ans1 = 0
	ans2 = 0
	dif = max(m[0] - m[1], 0)
	for i in range(1, n):
		if m[i] < m[i-1]:
			ans1 += m[i-1] - m[i]
			dif = max(dif, m[i-1] - m[i])
	for i in range(0, n - 1):
		ans2 += min(m[i], dif)
	return ans1, ans2


if __name__ == "__main__":
    testcases = input()
     
    for caseNr in xrange(1, testcases+1):
        n = raw_input()
        m = raw_input()
        ans1, ans2 = solve(int(n), m)
        print("Case #%i: %s %s" % (caseNr, ans1, ans2))