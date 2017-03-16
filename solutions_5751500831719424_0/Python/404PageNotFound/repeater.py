import math
import numpy as np

'''
a = [1,2,3,10,12]
a.append(6)
b = np.array(a)
print b
print np.median(b)
'''

f = open('A-small-attempt0.in','r')
T = int(f.readline().strip())
w = open('repeaterOut1.txt', 'w')
it = lambda x: int(x)
for ic in range(T):
	stri = f.readline().strip()
	N = int(stri[0])
	arr = ['']*N
	for i in range(N):
		arr[i] = f.readline().strip()
	charArr = [x[:] for x in [[]]*N]
	curChar = ''
	for i in range(N):
		strLen = len(arr[i])
		curChar = arr[i][0]#Initialize the current character
		cnt = 1
		for j in range(1,strLen):
			c = arr[i][j]#Obtain the letter
			if c != curChar:
				charArr[i].append([curChar,cnt])
				curChar = c
				cnt = 1
			else:
				cnt += 1
		charArr[i].append([curChar,cnt])
		#print charArr[i]
	possible = True
	#Now do a quick length check to see if the character barriers are present
	length = len(charArr[0])
	for i in range(1,N):
		if (len(charArr[i]) != length):
			possible = False
	#print possible
	#Check to see that all the barriers are the same
	if possible == True:
		for i in range(1,N):
			for j in range(length):
				if charArr[i][j][0] != charArr[0][j][0]:
					possible = False
	#print possible
	#Now for each barrier, find the median of all of them		
	diff = 0
	if possible == True:
		for i in range(length):
			a = []
			for j in range(N):#Append the numbers
				a.append(charArr[j][i][1])
			b = np.array(a)
			med = np.median(b)
			req = 0
			for i in range(N):
				req += abs(a[i]-med)
			diff += req
	diff = int(diff)
	if possible == True:
		w.write("Case #" + str(ic+1) +": " + str(diff) + "\n")
	else:
		w.write("Case #" + str(ic+1) +": Fegla Won\n")
