import string
import operator
T =int(input())
al= string.ascii_uppercase
for case in range(1,T+1):
	N = int(input())
	p = [int(s) for s in raw_input().split(' ')]
	p2={}
	d =''
	track= sum(p)
	for i in range(0,N):
		p2[al[i]]=p[i]
	#print p2
	while(1):
		sorted_x = sorted(p2.items(), key=operator.itemgetter(1),reverse = True)
		first = sorted_x[0][0]
		second = sorted_x[1][0]
		#print sorted_x
		if(p2[first]==0):
			break
		p2[first] = p2[first]-1
		d+=first
		track-=1
		#print track
		if not(track==2):
			if(p2[first]>p2[second]):
				p2[first] = p2[first]-1
				d+=first
				track-=1
			elif(p2[first]<p2[second] ):
				if(p2[second]>0):
					p2[second] =p2[second]-1
					d+=second
					track-=1
		#print p2
		d+=' '
	print 'Case #{}: {}'.format(case,d)
		
	