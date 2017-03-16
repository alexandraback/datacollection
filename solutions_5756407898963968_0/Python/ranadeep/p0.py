def func(Ar,Br):
	Ar.sort()
	Br.sort()
	c = 0
	iA, iB = 0, 0
	while (iA < len(Ar)) and (iB < len(Br)):
		if (Ar[iA] < Br[iB]):
			iA+=1
		elif (Ar[iA] > Br[iB]):
			iB+=1
		else:
			n = Ar[iA]
			iA+=1
			iB+=1
			c+=1
	if(c==0):
		return "Volunteer cheated!"
	elif(c==1):
		return n
	elif(c>1):
		return "Bad magician!"


def takeInput():
	for c in range(int(input())):
		a = int(input())-1
		for i in range(4):
			if(i==a): Ar = list(map(int,input().split()))
			else: input()
		b = int(input())-1
		for i in range(4):
			if(i==b): Br = list(map(int,input().split()))
			else: input()
		print("Case #{}: {}".format(c+1, func(Ar,Br)))
		

takeInput()