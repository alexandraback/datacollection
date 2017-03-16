#
# Google Code Jam 2015
# Roaund 1A: A. Mushroom Monster
# submission by EnTerr
#

'''
Input 
4
4
10 5 15 5
2
100 100
8
81 81 81 81 81 81 81 0
6
23 90 40 0 100 9

Output 
Case #1: 15 25
Case #2: 0 0
Case #3: 81 567
Case #4: 181 244
'''

import sys
from time import clock


f = open(sys.argv[1])
def input(): return f.readline().strip();

       
def countMushrooms(m):
    a = 0
    spd = 0
    
    x = m[0]
    for y in m[1:]:
        if y < x: 
            # proof something was eaten
            a += x-y
            spd = max(spd, x-y) 
        x = y
    
    b = 0
    x = m[0]
    for y in m[1:]:
        b += min(spd, x)
        x = y
    
    return a, b

#clk = clock()

for caseNo in xrange(1, int(input())+1):
    input() #skip N line
    m = map(int, input().split())
#    print >>sys.stderr, caseNo
    a,b = countMushrooms(m)
    print 'Case #%d:' % caseNo, a, b
    
#print >>sys.stderr, 'time= %.1f seconds' % (clock()-clk )

