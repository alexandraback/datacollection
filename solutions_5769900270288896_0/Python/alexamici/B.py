import itertools as it
for tc in range(input()):
	R,C,N=map(int,raw_input().split())
	res=float('inf')
	for t in it.combinations(range(R*C),N):
		u=0
		for n1 in t:
			x1,y1=n1%C,n1//C
			for n2 in t:
				x2,y2=n2%C,n2//C
				if x1==x2 and (y1==y2+1 or y1==y2-1) or \
					y1==y2 and (x1==x2+1 or x1==x2-1):
						u+=1
		res=min(res,u//2)
	print'Case #{}: {}'.format(tc+1,res)