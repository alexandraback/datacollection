def displayArray(my_array):
	for i in range(len(my_array)):
		print i

for tc in range(1, int(raw_input())+1):
	y = ''
	#print

	#N, P = map(int, raw_input().split())
	B, N = map(int, raw_input().split())
 	mi = map(int, raw_input().split())

 	barbers = [0] * B

 	###CHECK FOR RECURRSION
 	
 	counterRecursion = 0
 	maxRecursion = N
 	#print maxRecursion
	barbers2 = barbers[:]

 	while True and maxRecursion >= 0:
 		#print barbers
 		#not (all(x == barbers[0] for x in barbers)) and barbers != [0] * B:
 		minimum = min(barbers2)
 		index_minimun = barbers2.index(minimum)
 		barbers2[index_minimun] += mi[index_minimun]
 		counterRecursion +=1
 		if (all(x == barbers2[0] for x in barbers2)) :
 			break
 		maxRecursion -=1

 	#print 'counterRecursion', (counterRecursion)
 	#print 'N, N % counterRecursion', N, N % (counterRecursion)

 	#print maxRecursion
 	if N % counterRecursion == 0 and maxRecursion != -1:
 		#print 'A'
 		#y= counterRecursion

 		for time in range(counterRecursion-1):
 			minimum = min(barbers)
 			index_minimun = barbers.index(minimum)
 			barbers[index_minimun] += mi[index_minimun]

		minimum = min(barbers)
		index_minimun = barbers.index(minimum)
		#print 'index_minimun', index_minimun
 		y= index_minimun+1



 	else:
 		#print 'B'

 		if maxRecursion != -1:
	 		times = N % counterRecursion
	 	else:
	 		times = N

	 	#print barbers

 		for time in range(times-1):
 			minimum = min(barbers)
 			index_minimun = barbers.index(minimum)
 			barbers[index_minimun] += mi[index_minimun]

		minimum = min(barbers)
		index_minimun = barbers.index(minimum)
		#print 'index_minimun', index_minimun
 		y= index_minimun+1


 	# for n in range(1, N):
 	# 	minimum = min(barbers)
 	# 	index_minimun = barbers.index(minimum)
 	# 	barbers[index_minimun] += mi[index_minimun]

	#minimum = min(barbers)
	#index_minimun = barbers.index(minimum)
 	#print index_minimun+1
	index_minimun = 0

	#NOTE OUTPUT: y
	#if y != ''
	print "Case #{}: ".format(tc) + "{}".format(y)
	#else:
	#print "Case #{}: ".format(tc) + "{0:.6f}".format(y)
		
	
