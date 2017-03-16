def evac(S):
	if(S[0][1]>S[1][1]+1):
		print(S[0][0], end="")
		print(S[0][0], end=" ")
		S[0][1] = S[0][1]-2
		evac(sorted(S,key=byNum,reverse=True))
	elif (S[0][1]>S[1][1]):
		print(S[0][0], end=" ")
		S[0][1] = S[0][1]-1
		evac(sorted(S,key=byNum,reverse=True))
	elif S[0][1]==S[1][1]:
		if (len(S)==2):
			print(S[0][0], end="")
			print(S[1][0], end=" ")
			S[0][1] = S[0][1]-1
			S[1][1] = S[1][1]-1
			if (S[1][1]==0):
				S.remove([S[1][0],S[1][1]])
				S.remove([S[0][0],S[0][1]])
			else:
				evac(sorted(S,key=byNum,reverse=True))
		else:
			print(S[0][0], end=" ")
			S[0][1] = S[0][1]-1
			if (S[0][1]==0):
				S.remove([S[0][0],S[0][1]])
			evac(sorted(S,key=byNum,reverse=True))
def byNum(S):
	return S[1]
T = int(input())
for i in range(1,T+1):
	N = int(input())
	S = []
	for j in range(0,N):
		S.append([chr(ord('A')+j),0])
	k=0
	for l in input().split(" "):
		S[k][1] = int(l)
		k+=1
	S = sorted(S,key=byNum,reverse=True)
	print("Case #{}: ".format(i),end="")
	evac(S)
	print()