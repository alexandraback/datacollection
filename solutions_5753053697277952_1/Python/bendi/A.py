for case in range(1, int(input())+1):
	N = int(input())
	senators = list(map(int,input().split()))
	result = []
	empty = False
	while not empty:
		mainPartyHas = 0
		mainPartyIs = 0
		totalSenators = 0
		otherRemaining = -1
		tripleTie = False
		for i in range(N):
			totalSenators += senators[i]
			if senators[i] > mainPartyHas:
				mainPartyHas = senators[i]
				mainPartyIs = i
		#we got biggest. Is there any kind of tie?
		for i in range(N):
			if (senators[i] == mainPartyHas) and (i != mainPartyIs):
				if otherRemaining == -1:
					otherRemaining = i
				else:
					tripleTie = True
		if totalSenators == 2 :
			result.append(chr(mainPartyIs+ord('A'))+chr(otherRemaining+ord('A')))
			empty = True
		else:
			if (otherRemaining != -1) and (not tripleTie) :
				result.append(chr(mainPartyIs+ord('A'))+chr(otherRemaining+ord('A')))
				senators[otherRemaining] -= 1
			else:
				result.append(chr(mainPartyIs+ord('A')))
			senators[mainPartyIs] -= 1
	print ("Case #%d: %s" % (case," ".join(result)))
