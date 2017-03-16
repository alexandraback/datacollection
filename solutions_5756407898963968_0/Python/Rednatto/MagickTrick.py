
import sys

def solveThis( datafile ):
	numTests = int( datafile.readline() )
	
	rownum = 0
	firstrow = None
	secondrow = None
	possible = None
	
	for case in range(1,numTests+1):
		
		rownum = int( datafile.readline() )
		for row in range(rownum):
			firstrow = datafile.readline()
		for row in range( 4-rownum ):
			datafile.readline() #Discard
			
		rownum = int( datafile.readline() )
		for row in range(rownum):
			secondrow = datafile.readline()
		for row in range( 4-rownum ):
			datafile.readline() #Discard
			
		firstrow = firstrow.strip()
		firstrow = firstrow.split()
		
		secondrow = secondrow.strip()
		secondrow = secondrow.split()
		
		possible = getPossibles( firstrow, secondrow )
		
		output( possible, case )


def output( possibles, case ):
	if len(possibles) == 0:
		print( "Case #{:d}: Volunteer cheated!".format( case ) )
	elif len(possibles) == 1:
		print( "Case #{:d}: {:d}".format( case, int(possibles[0]) ) )
	else:
		print( "Case #{:d}: Bad magician!".format( case ) ) 
		
		
def getPossibles( first, second ):
	possible = []
	for e in first:
		if e in second:
			possible.append( e )
			
	return possible
	
if len(sys.argv) != 2 :
	sys.exit( "Give correct files!" )

try:
	data = open( sys.argv[1], "r" )
except IOError:
	sys.exit( "Couldn't open file!" )
	
solveThis( data )

data.close()

