def findMatch(a,b):
	a.sort()
	b.sort()
	result=[]
	idx=0
	for i in a:
		while i>b[idx]:
			idx+=1
			if idx>3:
				return result
		if i==b[idx]:
			result.append(i)
	return result

cases = int(raw_input())
for c in xrange(cases):
    line_a=int(raw_input())
    for i in xrange(4):
    	tmp = map(int,raw_input().split())
    	if i+1 == line_a:
    		a=tmp
    line_b=int(raw_input())
    for i in xrange(4):
    	tmp = map(int,raw_input().split())
    	if i+1 == line_b:
    		b=tmp
    res=findMatch(a,b)

    if len(res)==1:
    	print "Case #%d: %d" % (c+1,res[0])
    elif len(res)==0:
    	print "Case #%d: Volunteer cheated!" % (c+1)
    else:
    	print "Case #%d: Bad magician!" % (c+1)

