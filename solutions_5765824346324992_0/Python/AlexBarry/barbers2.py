from fractions import gcd

#fin_name = 'sample_input.in'
fin_name = 'B-small-attempt2.in'

fin = open( fin_name, 'r' )

case_count = int( fin.readline() )
cases = [None]*(case_count)
for i in range(case_count):
	barberCount, yourPos = tuple( int(arg) for arg in fin.readline().split() )
	barbersSpeeds = tuple( int(arg) for arg in fin.readline().split() )
	#if len(barbersSpeeds) != barberCount: raise Exception()

	cases[i] = ( yourPos, barberCount, barbersSpeeds )


def getFirstNonBusyBarber( barbers ):
	return barbers.index(0)

def waitForBarbers( barbers ):
	waitTime = min(barbers)
	if waitTime == 0: return
	for i in range( len(barbers) ):
		barbers[i] -= waitTime


def handleCase( case ):
	yourPos, barberCount, barberSpeeds = case
	barbers = [0]*barberCount

	period_minutes = product( barberSpeeds )
	period_people = 0
	for barberSpeed in barberSpeeds:
		if period_minutes % barberSpeed != 0: raise Exception()
		period_people += period_minutes/barberSpeed
	
	#repeatsEvery_people = [ repeatsEvery_x_minutes / barberSpeed 
	print 'mins: %d' % period_minutes,
	print 'people: %d' % period_people,
	print 'reducing yourPos from %d' % yourPos,
	yourPos = (  ( yourPos - 1 )  % period_people  ) + 1
	#yourPos = yourPos % period_people 
	print 'to %d' % yourPos,
	if yourPos == 0: return 1 # 1st barber
	for i in range(yourPos):
		#print barbers, 
		waitForBarbers( barbers )
		#print barbers, 
		myBarber = getFirstNonBusyBarber( barbers )
		#print myBarber + 1
		barbers[myBarber] += barberSpeeds[myBarber]

	return myBarber + 1

def product( barbersSpeeds ):
	prod = 1
	for barbSpeed in barbersSpeeds:
		prod *= barbSpeed
	return prod

def myProd( barbersSpeeds ):
	prod = 1
	#for barbSpeed in barbersSpeeds:
	#	if prod > 1 and barbSpeed % prod == 0:
	#		prod = max(prod, barbSpeed)
	#	else:
	#		prod *= barbSpeed
	#return prod

	i = 2
	if all( [ x < 2 for x in barbersSpeeds ] ): return 2
	while True:
		if all( [ x % i == 0 for x in barbersSpeeds ] ):
			return i
		

debug = True

fout_name = fin_name + '.out'
fout = open( fout_name, 'w' )
for case_index, case in enumerate(cases):
	case_num = case_index + 1

	if debug:
		myPos, barberCount, barbers = case
		print '%4d:' % case_num, 
		print '(%d)' % myPos,
		print '%s;' % list(barbers),

	myBarber = handleCase( case )
	toWrite = 'Case #%d: %d\n' % ( case_num, myBarber )
	if debug:
		#print '%4d: %s; %d' % ca
		print '%d' % myBarber
	fout.write( toWrite )












		
