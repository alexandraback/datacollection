import math
import numpy as numpy


inp=open('A-large.in', 'r')
out=open("A-large.out", 'w')

T=int(inp.readline())
for index in range(T):
	N=int(inp.readline())
	temp = [int(x) for x in (inp.readline()).split()] 
	senate=[];
	total=0;
	for j in range(N):
		total=total+temp[j]
		senate.append((temp[j],j))
	senate.sort(key=lambda tup: tup[0])
	result=""
	while(total!=0):
		temp=senate.pop()
		result=result+chr(ord('A')+temp[1]);
		temp=(temp[0]-1, temp[1]); total=total-1;
		if senate[0][0]>total/2:
			result=result+chr(ord('A')+senate[0][1])+" ";
			if senate[0][0]==1:
				senate.pop(); total=total-1; N=N-1;
			else:
				senate[0]=(senate[0][0]-1, senate[0][1]); total=total-1;
		else:
			result=result+" ";
		if temp[0]!=0:
			senate.append(temp); senate.sort(key=lambda tup: tup[0])
		else:
			N=N-1
	out.write('Case #{}: {}\n'.format(index+1, result))




inp.close()
out.close()