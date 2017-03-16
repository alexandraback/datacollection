T=input()
for i in range(T):
	r1=input()
	x=[]
	for j in range(4):
		s=raw_input();
		x.append(map(int, s.strip().split(' ')))
	r2=input()
	y=[]
	for j in range(4):
		s=raw_input();
		y.append(map(int, s.strip().split(' ')))
	possibleNum = [val for val in x[r1-1] if val in y[r2-1]]
	if len(possibleNum)==1:
		print 'Case #'+str(i+1)+': '+str(possibleNum[0])
	elif len(possibleNum)>1:
		print 'Case #'+str(i+1)+': Bad magician!'
	else:
		print 'Case #'+str(i+1)+': Volunteer cheated!'
