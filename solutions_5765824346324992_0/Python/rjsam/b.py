import sys
import math
import scipy
import operator
import fractions

def main():
    cCnt = int(sys.stdin.readline().strip())
    for i in range(cCnt):
        bCnt, nVal = tuple([int(x.strip()) for x in sys.stdin.readline().split()])
        bList = [int(x.strip()) for x in sys.stdin.readline().split()]

        if len(set(bList)) == 1:
            print("Case #{0}: {1}".format(i+1, (nVal-1)%bCnt+1))
            continue

        pVal = gcdCalc(bList)
        cVal = sum([pVal/x for x in bList])
        nVal = nVal%cVal
        if nVal == 0:
            nVal = cVal
        sList = []
        for j in range(nVal):
            sList.extend([(bList[x]*j, x) for x in range(bCnt)])

        sList.sort()
        print("Case #{0}: {1}".format(i+1, sList[nVal-1][1]+1))

    return 0

def gcdCalc(iList):
    if len(iList) == 2:
        return iList[0]*iList[1]/fractions.gcd(iList[0], iList[1])
    aVal = iList[0]
    bVal = iList[1:]
    gcVal = gcdCalc(bVal)
    return aVal*gcVal/fractions.gcd(aVal, gcVal)

def lcmCalc(iList):
    iList = list(set(iList))
    nVal = reduce(operator.mul, iList)
    return nVal/gcdCalc(iList)

#print(gcdCalc([1,2,3,4,5]))
main()
