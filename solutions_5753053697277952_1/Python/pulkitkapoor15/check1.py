testCases = int(raw_input())
for _ in xrange(testCases):
	nets = int(raw_input())
	list_Arr = map(int,raw_input().split())
	anss = sum(list_Arr)
	metas = max(list_Arr);
	calcs = 'Case #'+str(_+1)+': ';
	while anss > 0 :
		metas = max(list_Arr)
		detec = 0;
		for i in xrange(nets):
			if detec == 2 : 
				break;
			if list_Arr[i] == metas :
				anss -= 1;
				calcs+=chr(i+65)
				list_Arr[i]-=1;
				detec+=1;
		
		calcs += ' ';
	xenta = calcs.split()
	if len(xenta[-1]) == 1 :
		calcs = ' '.join(xenta[:-2])
		if len(xenta[-2]) == 1 :
			calcs += ' ' + xenta[-2]+xenta[-1]
		else:
			calcs += ' '+xenta[-2][0]+' '+xenta[-2][1]+xenta[-1]
	print calcs;