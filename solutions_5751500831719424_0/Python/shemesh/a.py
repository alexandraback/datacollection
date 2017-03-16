import random
import math
import sys
import time

def debug(s):
	sys.stderr.write(str(s) + '\n')

def get_params(*types):
	line = (raw_input()).split()
	params = []
	for i in range(len(types)):
		params += [types[i](line[i])]
		
	if len(params)==1:
		return params[0]
		
	return tuple(params)
	
def bin_search(s,e,v,cmpfunc):
	if e-s<=1:
		return s
	m = (s+e)/2

	if cmpfunc(m,v):
		return bin_search(s,m,v,cmpfunc)
	else:
		return bin_search(m,e,v,cmpfunc)
	
class time_est:
	def __init__(self,totnum,iternum):
		self.totnum = totnum
		self.iternum = iternum
		self.start_time = time.time()
		
	def calc_time(self,iter):
		if iter == self.iternum:
			till_now = time.time() - self.start_time
			till_end = till_now * (self.totnum - iter) / (iter)
			debug('Estimated time to finish = %f seconds' % (till_end))
			


Output = []
T = get_params(int)
te = time_est(T,10)

for t in xrange(T):
	te.calc_time(t)
	if t % 10 == 0:
		debug('Started %d' % t)
		

	N = get_params(int)
	strs = []
	details = []
	letterss = []
	for i in range(N):
		l=raw_input()
		cur_letter = l[0]
		num_letter = 0
		num_letters = []
		letters = cur_letter
		for j in range(len(l)):
			if l[j]==cur_letter:
				num_letter += 1
			else:
				num_letters += [num_letter]
				cur_letter = l[j]
				letters += cur_letter
				num_letter = 1
		num_letters += [num_letter]
		letterss += [letters]
		details += [num_letters]

	noSol = False
	last = letterss[0]
	for l in letterss:
		if l!=last:
			noSol = True
			break
	if noSol==False:
		detailss = []
		for i in range(len(details[0])):
			detailss += [[]]
			for j in range(N):
				detailss[i]+=[details[j][i]]
		debug(detailss)
		sum = 0
		for l in detailss:
			l.sort()
			a = l[len(l)/2]
			idx2 = len(l)/2-1
			if idx2<0:
				idx2=0
			b = l[idx2]
			
			s1 = 0
			s2 = 0
			for n in l:
				s1 += abs(n-a)
				s2 += abs(n-b)
			sum += min(s1,s2)
		Output += ['Case #%d: %d' % (t+1,sum)]
	else:
		Output += ['Case #%d: Fegla Won' % (t+1)]
	
			

	#Output += [''.join([str(k) for k in sol])]
	

		
for l in Output:
	print l
