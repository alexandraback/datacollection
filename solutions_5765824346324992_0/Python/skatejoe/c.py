import sys

def processTest():
    line = f.readline()[:-1].split(' ')
    B = int(line[0])
    N = int(line[1])
    B = [0 for x in range(B)]
    M = [int(x) for x in f.readline()[:-1].split(' ')]
    isFound = False
    def findEmpty():
        mini  = sys.maxint
        minloc = 0
        for i in range(len(B)):
            if B[i]<=0:
                return i
            if B[i]<mini:
                minloc = i
                mini = B[i]
        for i in range(len(B)):
            B[i]-=mini
        return minloc

    customer = 0
    while N>0:
        barber = findEmpty()
        #loop
        isEmpty = True
        for b in B:
            if b!=0:
                isEmpty = False
        if customer>0 and isEmpty:
            while N-customer>0:
                N-=customer
            #print(B,N,isEmpty)
        B[barber]+=M[barber]
        N-=1
        customer+=1
        if N==0:
            return barber+1
    return B

f = open(sys.argv[1],'r')
maxtests = int(f.readline())
testnum = 1
while testnum <= maxtests:
    answer = processTest()
    print('Case #'+str(testnum)+': '+ str(answer))
    testnum +=1

f.close()
