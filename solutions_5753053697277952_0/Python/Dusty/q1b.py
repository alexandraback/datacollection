fileout = open('output.out', 'w')
filein = open('A-small-attempt0.in', 'r')

alphabet = ['A', 'B', 'C', 'D', 'E','F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

T = int(filein.readline()) #Number of cases

for t in range(T):
	N = int(filein.readline())
	partyNumbers = (filein.readline()).split(' ')

	sumT = 0
	for i in partyNumbers:
		sumT += int(i)
	resultOut = ''

	while(sumT > 0):
		#find max party
		result = ''

		for z in range(2):
			maxP = 0
			maxi = 0
			for i in range(len(partyNumbers)):
				if(int(partyNumbers[i])>maxP):
					maxP = int(partyNumbers[i])
					maxi = i
			#check for majority
			fail = False
			if(z == 1):
				temp = int(partyNumbers[maxi])-1
				check = (sumT-1)/2
				fail = False
				for x in range(len(partyNumbers)):
					if(x == maxi):
						if(temp>check):
							fail = True
					elif(int(partyNumbers[x])>check):
						fail = True
				if(check == 0):
					fail = False

			if(not fail):
				partyNumbers[maxi] = str(int(partyNumbers[maxi])-1)
				result += alphabet[maxi]
				sumT -= 1

		resultOut += ' ' + result

	fileout.write('Case #'+str(t+1)+': '+str(resultOut)+'\n')




	# always evacuate two people of party with the most people

