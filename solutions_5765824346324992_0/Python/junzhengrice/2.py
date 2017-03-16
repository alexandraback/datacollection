'''
'''

file = open('in.txt','r')
out = open('out.txt','w')
test_cases = file.readlines()

# greatest comment divisor
def GCD(a,b):
    if b > a :
        b , a = a, b
    if b == 0:
        return a
    else:
        return GCD(b,a%b)

def LCM(a,b):
    return a * b // GCD(a,b)
        
def compute(ms,B,N):
    # least common multiple of array  
    lcm = ms[0]
    gcd = ms[0]
    for i in xrange(1,B):
        lcm = LCM(lcm,ms[i])
        gcd = min(gcd,GCD(ms[i],ms[i-1]))
        
        print i,lcm, gcd
            
    print "lcm: ",lcm   
    print "gcd: ",gcd   
            
    # total in a lcm time
    slot = 0
    for i in xrange(0,B):
        slot += lcm / ms[i]
    
    print "slot: ",slot
    
    left = N % slot
    print "left: ",left
    if left == 0:
        left = slot
    
    start = 0
    count = 0
    while start < lcm:
        for i in xrange(0,B):
            if start % ms[i] == 0:
                count += 1
                if count == left:
                    return i+1
        start += gcd
    
    return 1
    

lineId = 1
caseId = 0
while lineId < len(test_cases):
    caseId += 1
    (B,N) = tuple(map(lambda x:int(x),test_cases[lineId].strip().split(' ')))
    ms = map(lambda x:int(x),test_cases[lineId+1].strip().split(' '))
    
    answer = compute(ms,B,N)
    
    print >> out, "Case #%d: %d" % (caseId,answer)
    #print "Case #%d: %d" % (caseId,answer)
    
    lineId += 2

file.close()
out.close()