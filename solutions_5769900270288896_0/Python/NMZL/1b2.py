
def solution(r,c,n):
	table=[[0 for j in xrange(c+2)] for k in xrange(r+2)]

	for j in xrange(1,r+1):
		table[j][0]=-1
		table[j][c+1]=-1
	for k in xrange(1,c+1):
		table[0][k]=-1
		table[r+1][k]=-1	

	for row in xrange(1,r+1):
		for col in xrange(1,c+1):
			if table[row-1][col]!=-1:
				table[row][col]+=1
			if table[row+1][col]!=-1:
				table[row][col]+=1
			if table[row][col+1]!=-1:
				table[row][col]+=1
			if table[row][col-1]!=-1:
				table[row][col]+=1

	j=r*c
	level=4

	while j>n:
		for row in xrange(1,r+1):
			for col in xrange(1,c+1):
				if table[row][col]==level:
					j-=1
					table[row-1][col]-=1
					table[row+1][col]-=1
					table[row][col-1]-=1
					table[row][col+1]-=1
					table[row][col]=-1
					if j==n:
						return table
		level-=1
	return table

t=input()
for i in xrange(t):
	[r,c,n]=[int(x) for x in raw_input().split(' ')]
	table=solution(r,c,n)
	result=0
	for j in xrange(1,r+1):
		for k in xrange(1,c+1):
			if table[j][k]>0:
				result+=table[j][k]
	print 'Case #%d: %d' %(i+1, result/2)