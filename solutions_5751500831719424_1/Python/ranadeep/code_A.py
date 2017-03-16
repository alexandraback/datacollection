def analy(st):
	a = [[st[0],1]]
	for i in range(1,len(st)):
		if (st[i] == st[i-1]):
			a[-1][-1] += 1
		else:
			a.append([st[i],1])
	return a

def checkA(a,ar):
	if (len(ar) != len(a)):
		return None
	for i in range(len(a)):
		if a[i][0] != ar[i][0]:
			return None
	return a

def med(A):
	rt = 0
	A.sort()
	for i in range(len(A)):
		if(i < len(A) - i - 1):
			rt += A[len(A) - i - 1] - A[i]
		else:
			break
	return rt

def takeInput():
	for t in range(int(input())):
		n = int(input())
		f = True
		prim = analy(input())
		k = [prim]
		for inp in range(n-1):
			p = analy(input())
			if(f and checkA(p,prim) == None):
				f = False
			else:
				k.append(p)
		if(f):
			rt = sum([med([k[i][j][1] for i in range(len(k))]) for j in range(len(k[0]))])
			print("Case #{}: {}".format(t+1,rt))
		else:
			print("Case #{}: Fegla Won".format(t+1))


takeInput()



















