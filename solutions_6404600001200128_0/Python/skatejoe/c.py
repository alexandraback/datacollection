import sys

def processTest():
    N = int(f.readline()[:-1])
    ms = [int(x) for x in (f.readline()[:-1]).split(' ')]
    eaten = 0
    maxdiff = 0
    for i in range(len(ms)-1):
        diff = ms[i]-ms[i+1]
        if diff>0:
            eaten +=diff
        if diff>maxdiff:
            maxdiff = diff

    method2 = 0
    for i in range(len(ms)-1):
        method2+=min(ms[i],maxdiff)

    return eaten,method2

f = open(sys.argv[1],'r')
maxtests = int(f.readline())
testnum = 1
while testnum <= maxtests:
    method1,method2 = processTest()
    print('Case #'+str(testnum)+': '+ str(method1)+' '+str(method2))
    testnum +=1

f.close()
