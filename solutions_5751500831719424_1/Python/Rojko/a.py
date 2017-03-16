def normal(s):
	t = s[0]
	for i in range(1,len(s)):
		if s[i] != s[i-1]:
			t+=s[i]
	return t

def count(s):
	b = []
	b.append(1)
	for i in range(1,len(s)):
		if s[i] == s[i-1]:
			b[-1] = b[-1]+1
		else:
			b.append(1)
	return b

def cc(a,j):
	b = [a[i][j] for i in range(len(a))]
	b.sort()
	med = b[len(b)//2]
	poc = 0
	for x in b:
		poc+=abs(x-med)
	return poc

T = int(input())
for t in range(T):
	n = int(input())
	a = []
	x = input()
	vzor = normal(x)
	a.append(count(x))
	zle = False
	for i in range(1,n):
		x = input()
		if normal(x) == vzor:
			a.append(count(x))
		else:
			zle = True
	if zle:
		print("Case #",t+1,": Fegla Won",sep="")
	else:
		suc = 0
		for j in range(len(a[0])):
			suc+=cc(a,j)
		print("Case #",t+1,": ",suc,sep="")
