import collections
import sys

def read_line():
    return sys.stdin.readline().rstrip( '\n' )

def read_integer( base = 10 ):
    return int( read_line(), base )

def read_integers( base = 10 ):
    return [ int( x, base ) for x in read_line().split() ]

def read_float():
    return float( read_line() )

def read_floats():
    return [ float( x ) for x in read_line().split() ]

def read_string():
    return read_line().strip()

def read_strings():
    return read_line().split()

def input_string_stack():
    data = []
    for line in sys.stdin.readlines():
        data.extend( line.split() )
    data.reverse()
    return data

def input_integer_stack():
    return [ int( x ) for x in read_string_stack() ]

def bits( x ):
    return bin( x ).count( '1' )

class memoized( object ):
   def __init__( self, function ):
      self.function = function
      self.cache = {}
   def __call__( self, *arguments ):
      try:
         return self.cache[ arguments ]
      except KeyError:
         value = self.function( *arguments )
         self.cache[ arguments ] = value
         return value

T = read_integer()
for t in range( T ):
    print 'Case #%i:' % ( t + 1 ),
    N = read_integer()
    P = read_integers()
    while any( P ):
        p = P.index( max( P ) )
        P[ p ] -= 1
        if max( P ) <= sum( P )/2:
            q = None
        else:
            q = P.index( max( P ) )
            P[ q ] -= 1
        assert max( P ) <= sum( P )/2
        print chr( 65 + p ) + ( chr( 65 + q ) if q else '' ),
    print
