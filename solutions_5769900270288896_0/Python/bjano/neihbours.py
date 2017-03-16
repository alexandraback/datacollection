#!/bin/sh

#fname = 'B-small-attempt0'
fname = 'B-small-attempt1'

from itertools import *

def tokreader(filename):
	for line in open(filename):
		for item in line.strip().split():
			yield item

def readn(n):
    r = []
    for i in xrange(n):
        r.append(read)
    return r

def solve():
	inp = tokreader(fname+'.in')
	read = lambda: inp.next()
	readn = lambda x:[read() for i in xrange(x)]
	outp = open(fname+'.out','w')

	checkerror = 0

	T = int(read())
	for i in range(1,T+1):
		R,C,N = map(int,readn(3))
		
		ps = 0
		nr = N
		
		for j in range(1,R+1):
			if j%2 == 1:
				nr = nr - (C+1)/2
			else:
				nr = nr - C/2
					
		nr2 = nr			
		cornerpos = 0
		
		res = 0
		
		if (C == 1) and (R == 1):
			res = 0
		elif (C == 1) or (R == 1):
			p = C+R-1
			if (C+R)%2 == 1:
				if nr>0:
					nr -= 1
					res += 1
			if nr>0:
				res += nr*2
		else:
			if C%2 == 0:
				cornerpos += 1
			if R%2 == 0:
				cornerpos += 1
			if (C+R)%2 == 1:
				cornerpos += 1	
		
			edgepos = (C-1)/2 + (R-1)/2
		
			if C%2 == 1:
				edgepos += (R-1)/2   # X0X0X0X
			else:
				edgepos +=  (R-2)/2  # 0X0X0X  

			if R%2 == 1:
				edgepos += (C-1)/2   # X0X0X0X
			else:
				edgepos +=  (C-2)/2  # 0X0X0X  
		
		
			res = 0
				
			if nr <= 0:
				res = 0
			elif (nr <= cornerpos):
				res = nr*2
			else:
				res = cornerpos*2
				nr -= cornerpos
				if nr <= edgepos:
					res += nr*3
				else:
					res += edgepos*3
					nr -= edgepos
					res += nr*4
			
			print '(%da)  %d in %dX%d     nr: %d   corners: %d  edges: %d  => %d' % (i,N,R,C,nr2,cornerpos,edgepos,res)

			
		if (C%2==1) and (R%2==1) and (R>1) and (C>1):
			ps = 0
			nr = N
		
			for j in range(1,R+1):
				if j%2 == 0:
					nr = nr - (C+1)/2
				else:
					nr = nr - C/2
					
			nr2 = nr
			cornerpos = 4
			edgepos = (R-2)/2 + (C-2)/2
			edgepos = edgepos*2
			
			if nr <= 0:
				res2 = 0
			elif (nr <= cornerpos):
				res2 = nr*2
			else:
				res2 = cornerpos*2
				nr -= cornerpos
				if nr <= edgepos:
					res2 += nr*3
				else:
					res2 += edgepos*3
					nr -= edgepos
					res2 += nr*4
			
			print '(%db)  %d in %dX%d     nr: %d   corners: %d  edges: %d  => %d' % (i,N,R,C,nr2,cornerpos,edgepos,res2)
	
			if res2<res:
				res = res2
			
		
		checkres = 99999
		
		for j in product(range(2),repeat=R*C):
			if j.count(1) == N:
				nc = 0
				for i1 in range(0,R-1):
					for i2 in range(0,C):
						if (j[i1*C+i2]==1) and (j[(i1+1)*C+i2]==1):
							nc += 1
				for i1 in range(0,C-1):
					for i2 in range(0,R):
						if (j[i2*C+i1]==1) and (j[i2*C+i1+1]==1):
							nc +=1
				if nc < checkres:
					checkres = nc
		
		print 'checkres: %d' % (checkres)
			
		if (checkres != res):
			print 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
			print 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
			print 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
			checkerror = 1
#		if res<0:
#			res = 0
			
		res = 'Case #%d: %d\n'%(i,res)
		print res
		outp.write(res)
		

	outp.close()
	print 'finished'
	print checkerror