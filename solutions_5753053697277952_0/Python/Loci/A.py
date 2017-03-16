
cases = int(raw_input())



for case in range(cases):
	parties = int(raw_input())
	senators = [int(i) for i in raw_input().split()]

	answer = []

	allSenators = sum(senators)

	#print senators
	
	while 1:
		bunch = []
		m = max(senators)

		if len(senators) == 2:
			answer = ' '.join(['AB']*max(senators))
			break

		if allSenators == 2:
			for i,s in enumerate(senators):
				if s > 0:
					answer += chr(ord('A')+i)
			break

		for i,s in enumerate(senators):
			#if len(bunch) == 2:
			#	break
			if s == m:
				bunch.append(i)
				allSenators -= 1
				senators[i] -= 1
				#print senators
				break
		for index in bunch:
			answer += chr(ord('A')+index)
		answer += ' '

	#print answer
	
	

	print "Case #" + str(case+1) + ": " + ''.join(answer)

	#print 





