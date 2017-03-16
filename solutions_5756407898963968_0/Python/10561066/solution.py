# Python 3.4

# Codejam, 2014, Round Q, Problem A

import sys

def main() :
    TT = int( input() )
    for case in range( 1 , 1+TT ) :
        ANS_ONE = int( input() )
        for ii in range( 1 , 1+4 ) :
            CARDS_IN_ROW = ( int( x ) for x in input().split() )
            if ii == ANS_ONE : 
                answer = set( CARDS_IN_ROW )
            #end-if
        #end-for
        ANS_TWO = int( input() )
        for ii in range( 1 , 1+4 ) :
            CARDS_IN_ROW = ( int( x ) for x in input().split() )
            if ii == ANS_TWO :
                answer = answer & set( CARDS_IN_ROW )
            #end-if
        #end-for

        if len( answer ) == 0 :
            print( "Case #{case}: Volunteer cheated!".format( case=case , answer=answer ) )
            #mid-if
        elif len( answer ) == 1 :
            print( "Case #{case}: {answer[0]}".format( case=case , answer=list( answer ) ) )
            #mid-elif
        elif len( answer ) > 1 :
            print( "Case #{case}: Bad magician!".format( case=case , answer=answer ) )
        #end-elif
    return 0 # EXIT_SUCCESS
    #end-def-main


if __name__ == "__main__" :
    sys.exit( main() )
    #end-if


