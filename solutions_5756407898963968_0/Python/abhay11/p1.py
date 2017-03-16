numRuns=int(input())
for run in range(numRuns):
	pot=[False]*16
	r=int(input())-1
	for i in range(4):
		data=input().split()
		if i==r:
			for j in range(4):
				pot[int(data[j])-1]=True
	sol=[]
	r=int(input())-1
	for i in range(4):
		data=input().split()
		if i==r:
			for j in range(4):
				if pot[int(data[j])-1]:
					sol.append(data[j])
	if len(sol)==1:
		print("Case #"+str(run+1)+": "+sol[0])
	elif len(sol)==0:
		print("Case #"+str(run+1)+": Volunteer cheated!")
	else:
		print("Case #"+str(run+1)+": Bad magician!")
	