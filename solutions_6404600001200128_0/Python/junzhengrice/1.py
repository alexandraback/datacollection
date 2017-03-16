from __future__ import division
'''
Mushroom
'''

file = open('in.txt','r')
out = open('out.txt','w')
test_cases = file.readlines()


def methodA(ms,N):
    eaten = 0
    for i in xrange(1,N):
        if ms[i] - ms[i-1] < 0:
            eaten += ms[i-1] - ms[i]       
    return eaten

def methodB(ms,N):
    eaten = 0
    rate = 0 # every 10s
    for i in xrange(1,N):
        if ms[i-1] - ms[i] > rate:
            rate = ms[i-1] - ms[i]
            
    for i in xrange(0,N-1):
        if ms[i] <= rate:
            eaten += ms[i]
        else:
            eaten += rate
            
    return eaten

lineId = 1
caseId = 0
while lineId < len(test_cases):
    caseId += 1
    N = int(test_cases[lineId].strip())
    ms = map(lambda x :int(x), test_cases[lineId+1].strip().split(' '))
    
    a = methodA(ms,N)
    b = methodB(ms,N)
    
    print >> out, "Case #%d: %d %d" % (caseId,a,b)
    lineId += 2

file.close()
out.close()