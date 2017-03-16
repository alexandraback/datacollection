def get_stats(s):
	res=[]
	curr='-'
	count=0
	for c in s:
		if c==curr:
			count+=1
		else:
			res.append([curr,count])
			curr=c
			count=1
	res.append([curr,count])
	return res[1:]

fin=open('A-large.in')
fout=open('A.out','w')
cases=int(fin.readline())
for cas in xrange(1,cases+1):
	fout.write("Case #{}: ".format(cas))
	n=int(fin.readline())
	words=[]
	for i in xrange(n):
		words.append(get_stats(fin.readline().strip()))
	good=True
	m=len(words[0])
	for i in xrange(1,n):
		if len(words[i])!=len(words[0]):
			fout.write('Fegla won\n')
			good=False
			break
		for j in xrange(m):
			if(words[0][j][0]!=words[i][j][0]):
				fout.write('Fegla won\n')
				good=False
				break
		if not good:
			break
	if not good:
		continue
	tot=0
	for i in xrange(m):
		bst=1000000000000
		for j in xrange(1,101):
			cost=0
			for k in xrange(n):
				cost+=abs(j-words[k][i][1])
			bst=min(bst,cost)
		tot+=bst
	fout.write('{}\n'.format(tot))
fout.close()
fin.close()
	
