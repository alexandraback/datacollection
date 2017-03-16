from sys import stdin
import math

for case in range(int(stdin.readline())):
	n = int(stdin.readline())
	arrS = []
	numOp = 0
	impos = 0
	for i in range(n):
		arrS.append(stdin.readline())
	while(1):
		lenArr = []
		if len(arrS[0]) < 1:
			break
		curChar = arrS[0][0]
		#print('curChar = {}'.format(curChar))
		j = 0
		for s in arrS:
			count = 0
			for i in range(len(s)):
				if (s[i] == curChar):
					count += 1
					if i+1 == len(s):
						lenArr.append(count)
						arrS[j] = s[count:]
				else:
					lenArr.append(count)
					arrS[j] = s[count:]
					break
			j += 1
		if len(lenArr) != 0:
			median = sorted(lenArr)[(len(lenArr)//2)]
		for l in lenArr:
			numOp += abs(l - median)
			#print('addOp = {}, l = {}, median = {}'.format(abs(l-median), l, median))
		isfin = 0

		if len(lenArr) == 0:
			break
		if all(x == lenArr[0] for x in lenArr) and lenArr[0] == 0:
			break
		if 0 in lenArr:
			impos = 1
			break
	if impos == 1:
		ans = 'Fegla Won'
	else:
		ans = numOp
	print('Case #{}: {}'.format(case + 1, ans), end='\n')
	