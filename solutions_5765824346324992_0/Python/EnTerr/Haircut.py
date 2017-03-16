#
# Google Code Jam 2015
# Roaund 1A: B. Haircut
# submission by EnTerr
#

'''
Input 
 
3
2 4
10 5
3 12
7 7 7
3 8
4 2 1

Output 
Case #1: 1
Case #2: 3
Case #3: 1

'''

import sys
from time import clock


f = open(sys.argv[1])
def input(): return f.readline().strip();

       
def whichBarber(m, n):
    cache = {}
    b = len(m)
    status = [0] * b
    cache = { tuple(status): 0 }
    custNo = 1
    while custNo <= n:
        # find earliest free time, then take first barber
        mn = min(status)
        for i in xrange(b):
            status[i] -= mn
        for i in xrange(b):
            if status[i] == 0: break
        status[i] = m[i]
        tup = tuple(status)
        if tup in cache:
            #we found a loop, jump forward
            loop_len = custNo - cache[tup]
            #print 
            #print 'loop', n, custNo, loop_len, '=>', 
            n = custNo + (n - custNo) % loop_len
            #print n
        else:
            cache[tup] = custNo
            
        custNo += 1
        
    return i+1

clk = clock()

for caseNo in xrange(1, int(input())+1):
    b, n = map(int, input().split())
    m = map(int, input().split())
    print >>sys.stderr, caseNo
    print 'Case #%d:' % caseNo, whichBarber(m, n)
    
print >>sys.stderr, 'time= %.1f seconds' % (clock()-clk )

