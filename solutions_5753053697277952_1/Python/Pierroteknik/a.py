import string

def fin(P):
	l = []
	for i in P:
		l.append(int(i))
	max1 = max(l)
	indMax1 = l.index(max(l))
	l[indMax1] = 0
	max2 = max(l)
	indMax2 = l.index(max(l))
	if (max1==max2):
		l[indMax2] = 0
		reste = max(l)
		if (reste==0):
			return True
		else:
			return False
	else:
		return False

T = int(input())
for t in range(T):
	print("Case #" + str(t+1) + ": ",end="")

	letters = list(string.ascii_uppercase)
	# l = liste des uppercase letters indexées par des entiers
	l = []
	for i in range(0,len(letters)):
		l.append(letters[i])
	N = int(input())
	P = list(map(int,input().split()))
	while(not(fin(P))):
		indMax1 = P.index(max(P))
		P[indMax1]=P[indMax1]-1
		print(letters[indMax1],end=" ")
	while(max(P)>0):
		max1 = max(P)
		indMax1 = P.index(max(P))
		P[indMax1] -= 1
		max2 = max(P)
		indMax2 = P.index(max(P))
		P[indMax2] -= 1
		print(letters[indMax1],end="")
		print(letters[indMax2],end=" ")

	print("")
