def solve():
	n=input()
	stringz=[]
	for i in range(n):
		stringz.append(raw_input().replace(" ","").replace("\t",""))
	strs=[]
	for string in stringz:
		s=[]
		prev=string[0]
		count=1
		sgn=prev
		for char in string[1:]:
			if(char==prev):
				count+=1
			else:
				sgn+=char
				s.append((prev,count))
				count=1
			prev=char
		s.append((prev,count))
		strs.append((s,sgn))
	
	signature=strs[0][1]
	for string in strs:
		if string[1]!=signature:
			print "Fegla Won"
			return
	reps=[]
	for ch in signature:
		reps.append([])
	for string in strs:
		strsplit=string[0]
		for i in range(len(strsplit)):
			reps[i].append(strsplit[i][1])
	total=0
	for rep in reps:
		total+=equalize(rep)
	print total


diff_cnst=0
def diff(a):
	global diff_cnst
	return abs(diff_cnst - a)	
def equalize(rep):
	global diff_cnst
	diff_cnst=rep[0]
	min=sum(map(diff,rep))
	for val in rep[1:]:
		diff_cnst=val
		v=sum(map(diff,rep))
		if v<min:
			min = v
	return min



n=input()
for i in range(n):
	print "Case #"+str(i+1)+":",
	solve()
