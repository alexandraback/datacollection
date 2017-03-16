import math

T=int(input())
for t in range(T):
	nstrings=int(input())
	strings=[]
	chars=['A']*101
	nchars = [[1000]*101 for x in range(101)]
	possible=True
	nops=0
	maxuniquechar=-1
	
	for i in range(nstrings):
		string=input()
		uniquechar=0
		for j in range(len(string)):
			if j==0: #first character of the string
				if chars[uniquechar]=='A': #first string
					chars[uniquechar]=string[j]
				if string[j]==chars[uniquechar]:
					nchars[uniquechar][i]=1
				else:
					possible=False
			else:
				if string[j]!=string[j-1]:
					uniquechar+=1;
					if chars[uniquechar]=='A': #first string
						chars[uniquechar]=string[j]
					if chars[uniquechar]==string[j]:
						nchars[uniquechar][i]=1
					else:
						possible=False
				else:
					nchars[uniquechar][i]+=1
		if maxuniquechar==-1:
			#print('initializing maxuniquechar to '+str(uniquechar))
			maxuniquechar=uniquechar
		else:
			#print('max: '+str(maxuniquechar)+' uniquechar: '+str(uniquechar))
			if maxuniquechar!=uniquechar:
				possible=False
	
	if possible:
		for i in range(maxuniquechar+1):
			#print(nchars[i])
			nchars[i].sort()
			median=nchars[i][math.floor(nstrings/2)]
			for j in range(nstrings):
				nops+=abs(nchars[i][j]-median)
		print('Case #' + str(t+1) + ': ' + str(nops))
	else:
		print('Case #' + str(t+1) + ': Fegla Won')
