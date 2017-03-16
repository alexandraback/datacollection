import itertools
from itertools import *

# def combinationsWithItertools():
# 	i = 1
# 	for n in itertools.combinations("ABCD",3):
# 		print i,"[:]",n
# 		i += 1


for tc in range(1, int(raw_input())+1):
	R,C,N = map(int, raw_input().split())

	V = [i for i in range(R*C)]

	#print V

	noiseFinal = R*C*10

	for n in itertools.combinations(map(str,V),N):
		#print n
		#print n #('0', '1', '2', '3', '5', '6', '7', '8')
		noise = 0

		for n1 in n:

			n1 = int(n1)
			#print n
			if str(n1+1) in n:
				if (n1+1)/C == n1/C:
					#print 'n1, str(n1+1)', n1, str(n1+1)
					noise +=1
			if str(n1-1) in n:
				if (n1-1)/C == n1/C:
					#print 'n1, str(n1-1)', n1, str(n1-1)
					noise +=1
			if str(((n1/C)+1)*C+ n1%C) in n:
				#print 'n1, str(((n1/C)+1)*C+ n1%C)', n1, str(((n1/C)+1)*C+ n1%C)
				noise +=1
			if str(((n1/C)-1)*C+ n1%C) in n:
				#print 'str(((n1/C)-1)*C+ n1%C)', n1, str(((n1/C)-1)*C+ n1%C)
				noise +=1

		#print 'noise', noise
		noiseFinal = min(noiseFinal, noise)
	#print 'noiseFinal', noiseFinal











	print "Case #{}: ".format(tc) + "{}".format(noiseFinal/2)