from collections import *

f=open("A-small-attempt0.in","r")
T=int(f.readline().strip())

answers=[-2 for i in range(T)]

for i in range(T):
	matrix=[]
	ans1=int(f.readline().strip())
	for k in range(4):
		matrix.append(set([int(j) for j in list(f.readline().split())]))
	
	ans2=int(f.readline().strip())
	matrix2=[]
	for k in range(4):
		matrix2.append(set([int(j) for j in list(f.readline().split())]))
		
	inti=matrix[ans1-1].intersection(matrix2[ans2-1])
	s=len(inti)
	if s==0:
		answers[i]=0
	elif s>1:
		answers[i]=-1
	elif s==1:
		answers[i]=inti.pop()
	
f.close();

f=open("OUTPUT.txt","w")
for i in range(T):
	if answers[i]==0:
		f.write("Case #{}: Volunteer cheated!\n".format(i+1))
	elif answers[i]==-1:
		f.write("Case #{}: Bad magician!\n".format(i+1))
	else:
		f.write("Case #{}: {}\n".format(i+1,answers[i]))

f.close()
