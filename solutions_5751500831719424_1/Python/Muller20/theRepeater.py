'''
	codejam 2014
	the repeater
'''

def solve(l):
	pos = [0 for x in l]
	c = [0 for x in l]
	ins = l[0][0]
	costo = 0
	fine = False
	while not fine:	
		#controllo che ci sia almeno un carattere e inizializzo c
		ins = l[0][ pos[0] ]
		for i in range( len(l) ):
			if l[i][ pos[i] ] != ins:
				return -1
			c[i] = 0
		
		#calcolo c
		for i in range( len(l) ):
			while pos[i]<len(l[i]) and l[i][ pos[i] ] == ins:
				c[i] += 1
				pos[i] += 1
		#print( c )###############################
		
		#calcolo costo pareggio del nuovo carattere
		newcosto=10000000
		costosucc=1000000
		left=0
		while newcosto > costosucc:
			left+=1
			newcosto = costosucc
			costosucc = 0
			for i in range( len(l) ):
				if c[i] < left:
					costosucc += left-c[i]
				else:
					costosucc += c[i]-left
		
		#o tutti sono alla fine o nessuno
		fine = len(l[0])==pos[0]
		for i in range( len(l) ):
			if (len(l[i])==pos[i]) != fine:
				return -1
		costo += newcosto
		
	return costo
	
if __name__=='__main__':
	test = int(input())
	for t in range(test):
		n = int(input())
		l = []
		for i in range(n):
			l.append( input() )
		
		sol = solve( l )
		if sol!=-1:
			print("Case #" + str(t+1) + ": " + str(sol) )
		else:
			print("Case #" + str(t+1) + ": " + "Fegla Won" )