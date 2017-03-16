import sys

def readBoard( infile ):
	board = []
	
	for i in range(4):
		row = infile.readline().strip().split( " " )
		board.append( [int(x) for x in row] )
		
	return board

def solveTrick( infile ):
	guess1 = int( infile.readline() )
	board1 = readBoard( infile )
	set1 = set( board1[guess1 -1] )
	
	guess2 = int( infile.readline() )
	board2 = readBoard( infile )
	set2 = set( board2[guess2 -1] )
	
	overlap = set1.intersection(set2)
	
	if( len( overlap ) == 0 ):
		return "Volunteer cheated!"
	if( len( overlap ) == 1 ):
		return overlap.pop()
	return "Bad magician!"

def solve(infile):

	output = ""
	t_count = int( infile.readline() )
	
	for i in range( t_count ):
		
		answer = solveTrick( infile )
		output += "Case #{}: {}\n".format( i+1, answer )
		
	return output.strip()

if( __name__ == "__main__" ):
	infile_name = sys.argv[1]
	
	output = "__null__"
	with open( infile_name ) as f:
		output = solve( f )
		
	with open( infile_name + ".out", "w" ) as of:
		of.write( output )
	
	exit(0)