'''
Created on Apr 11, 2014

@author: dbaron
'''

def main():
   f = open('A-small-attempt0.in', 'r')
   T = int(readLine(f))
   for testCase in range(1, T+1):
      answerOne = int(readLine(f))
      cardsOne = [ readIntArray( f ),
                   readIntArray( f ),
                   readIntArray( f ),
                   readIntArray( f ) ]
      answerTwo = int(readLine(f))
      cardsTwo = [ readIntArray( f ),
                   readIntArray( f ),
                   readIntArray( f ),
                   readIntArray( f ) ]
      result = operate( answerOne, cardsOne, answerTwo, cardsTwo )
      print( "Case #%d: %s" % (testCase, result))
      
def operate( answerOne, cardsOne, answerTwo, cardsTwo ):
   setOne = set( cardsOne[answerOne - 1] )
   setTwo = set( cardsTwo[answerTwo - 1] )
   intersection = setOne & setTwo
   if len(intersection) == 0:
      return 'Volunteer cheated!'
   elif len(intersection) == 1:
      return intersection.pop()
   else:
      return 'Bad magician!'

def readIntArray( f ):
   return map( int, readLine(f).split() )

def readLine( f ):
   return f.readline().rstrip('\n')

if __name__ == '__main__':
    main()