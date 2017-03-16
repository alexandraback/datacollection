import numpy as np


def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""   
    return reduce(lcm, args)
    
    

f = open('B-small-attempt0.in', 'r')
fr = open('B-small-attempt0.out', 'w')
#f = open('A-large.in', 'r')
#fr = open('A-large.out', 'w')
line = f.readline()
#print line
ntot = int(line.split()[0])
for i in range(ntot):
    line = f.readline()
    numBarber, myPos = map(int, line.split()[:])
    line = f.readline()
    mylist = map(int, line.split()[:])
#    print n
#    print mylist
    mylcm = 1
    for j in range(numBarber):
        mylcm = lcm(mylcm, mylist[j])
    oneRoundPos = 0
    divList = np.zeros(numBarber)
    for j in range(numBarber):
        divList[j] = mylcm / mylist[j]
        oneRoundPos = oneRoundPos + divList[j]
#    print 'lcm ', mylcm
#    print 'oneRoundPos ', divList    
    myEffPos = int(myPos + oneRoundPos - 1) % int(oneRoundPos)
#    print 'myEffPos ', myEffPos   
    
    sumList = np.zeros(numBarber)
    tag = 0
    while(myEffPos > 0):
        # custom at the front goes to the first available barber
        sumList[tag] = sumList[tag] + mylist[tag]
        myEffPos = myEffPos - 1
        # update tag
        tag = np.argmin(sumList)
        # print 'range ', range(tag, (tag + numBarber) % numBarber, 1)
        # for k in range(tag, (tag + numBarber - 1) % numBarber, 1):
        #    if sumList[t] == sumList[k]:
        #        tag = k
#        tag = t
#        print 'k and t and sumList ', tag, t, sumList
    fr.write('Case #'+ str(i+1) + ': ' + str(tag+1) + '\n')
f.close()
fr.close()