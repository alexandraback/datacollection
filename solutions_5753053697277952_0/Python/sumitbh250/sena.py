t = int(input())
for i in range(t):
	n = int(input())
	num = list(map(int,input().split()))
	j = i+1
	ans = ""
	total = sum(num)
	while(total!=0):
		max1 = max(num)
		ind1 = num.index(max1)
		temp1=chr(ord('A')+ind1)
		total-=1
		num[ind1]-=1
		max2 = max(num)
		if((2*max2)>total):
			ind2 = num.index(max2)
			temp2 = chr(ord('A')+ind2)
			num[ind2]-=1
			total-=1
			ans = ans+temp1+temp2+" "
		else:
			ans = ans+temp1+" "
		'''if(total!=2):
			ind = num.index(max(num))
			num[ind]-=1
			total-=1
			temp=chr(ord('A')+ind)
			ans = ans+temp+" "
		else:
			maxi = max(num)
			if(maxi==2):
				ind = num.index(maxi)
				temp = chr(ord('A')+ind)
				ans = ans+temp+temp+" "
			else:
				ind1 = num.index(maxi)
				num[ind1]-=1
				ind2 = num.index(maxi)
				num[ind2]-=1
				temp1 = chr(ord('A')+ind1)
				temp2 = chr(ord('A')+ind2)
				ans = ans+temp1+temp2+" "
			total-=2'''

	print("Case #"+str(j)+": "+ans)
