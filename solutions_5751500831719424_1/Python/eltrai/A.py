#!/usr/bin/python

def readint ():
	return int(input())
def readarray ( f ):
	return map(f, input().split())

def solve(list):
	l2 = []
	checklen = False
	lastlen = 0
	for word in list:
		t = []
		last = ''
		for i in range(len(word)):
			if word[i] == last:
				t[-1][1] += 1
			else:
				last = word[i]				
				t.append([last, 1])
		l2.append(t)
		if checklen and lastlen != len(t):
			return "Fegla Won"
		lastlen = len(t)
		checklen = True
	
	count = 0
	#print(l2)
	for i in range(lastlen):
		if len(set([l2[j][i][0] for j in range(len(l2))])) > 1:
			return "Fegla Won"
		nums = [l2[j][i][1] for j in range(len(l2))]
		#print(nums)
		wanted = round(sum(nums)/float(len(nums)))
		#print(wanted)
		count += sum(map(lambda x: abs(x - wanted), nums))
		#print("Count=", count)
	
	return count
	

cases = readint()
for k in range(cases):
	N = readint()
	list = []
	for i in range(N):
		list.append(input())
	print('Case #' + str(k+1) + ': ' + str(solve(list)))
