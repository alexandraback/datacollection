#!/usr/bin/env python2
def readset():
	row=int(raw_input())
	a=[map(int,raw_input().split())for _ in xrange(4)]
	return set(a[row-1])
for t in xrange(1,1+int(raw_input())):
	s=readset()&readset()
	print"Case #%d:"%t,
	if len(s)==0:
		print"Volunteer cheated!"
	elif len(s)>1:
		print"Bad magician!"
	else:
		print next(iter(s))
