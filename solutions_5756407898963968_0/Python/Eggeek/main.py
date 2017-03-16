import sys
sys.stdin = open('test.txt','r')
sys.stdout = open('ans.txt','w')
cas = input()

def work(cas):
	r1 = input()
	l1 = []
	for i in xrange(1,5):
		if i == r1: l1 = map(int,raw_input().split())
		else: raw_input()
	r2 = input()
	l2 = []
	for i in xrange(1,5):
		if i == r2: l2 = map(int,raw_input().split())
		else: raw_input()
	set1 = set()
	for i in l1: set1.add(i)
	set2 = set()
	for i in l2: set2.add(i)
	x = set1 & set2
	if len(x)>1:
		print "Case #%d: Bad magician!"%cas
	elif len(x)==1:
		print "Case #%d: %d"%(cas,x.pop())
	elif len(x)==0:
		print "Case #%d: Volunteer cheated!"%cas

for i in xrange(1,cas+1):
	work(i)