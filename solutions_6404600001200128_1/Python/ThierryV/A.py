def displayArray(my_array):
	for i in range(len(my_array)):
		print i

for tc in range(1, int(raw_input())+1):
	y = ''

	N = int(raw_input())
	mi = map(int, raw_input().split())

	#1ST METHOD
	first = 0
	for p in range(N-1):
		if mi[p]> mi[p+1]:
			first +=  mi[p] - mi[p+1]

	#print first


	#2ND METHOD
	maxDiff = 0
	second = 0
	for p in range(N-1):
		maxDiff = max(maxDiff,mi[p] - mi[p+1])

	for p in range(N-1):
		#print
		#print p,mi[p] 
		if maxDiff >= mi[p]:
			second += mi[p]
		else:
			second += maxDiff


	#print maxDiff

	#second = ''
	#NOTE OUTPUT: y
	#if y != ''
	print "Case #{}: ".format(tc) + "{} ".format(first)+ "{} ".format(second)
	#else:
	#print "Case #{}: ".format(tc) + "{0:.6f}".format(y)
		
	
