#
# Google Code Jam 2016
# Roaund 1C: A. Senate Evacuation
# submission by EnTerr
#

'''
'''


import sys
from time import clock
from collections import defaultdict

f = open(sys.argv[1])
def input(): return f.readline().strip();

       
def senate_evacuation(Ps):
    '''
    '''
    while True:
        mx = max(Ps)
        if mx < 2 and sum(Ps) < 3:
            # 2 or less parties remaining, with 1 member each
            break
        i = Ps.index(mx)
        # throw one out
        Ps[i] -= 1
        print chr(ord('A') + i),
        
    # at this point, either 1 or 2 parties remaining, with 1 member each
    print ''.join(chr(ord('A') + i) for i, item in enumerate(Ps) if item>0)
    #assert sum(Ps) == 2
    return None


#clk = clock()

for caseNo in xrange(1, int(input())+1):
    #print >>sys.stderr, caseNo
    N = int(input())
    Ps = map(int, input().split())
    print 'Case #%d:' % caseNo, 
    senate_evacuation(Ps)
    
#print >>sys.stderr, 'time= %.1f seconds' % (clock()-clk )

