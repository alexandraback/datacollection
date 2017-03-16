cases=int(input())
for j in range(1,cases+1):
	num=int(input())
	arr=[]
	alps=input().split()
	for alp in alps:
		arr.append(int(alp))
	s=sum(arr)
	print('Case #'+str(j)+": ",end="")
	if(s%2==1):
		maxi2=arr.index(max(arr))
		s-=1
		arr[maxi2]-=1
		print(chr(maxi2+65),end=" ")
	while(s!=0):
		maxi=arr.index(max(arr))	
		s-=1
		arr[maxi]-=1
		if(s!=0):
			s-=1
			maxi2=arr.index(max(arr))
			arr[maxi2]-=1
			print(chr(maxi+65)+""+chr(maxi2+65),end=" ")
		else:
			print(chr(maxi+65),end="")
		maxi1=arr.index(max(arr))
		if(arr[maxi1]>sum(arr)/2):
			print("ERROR")
	print()
		
			
		
			