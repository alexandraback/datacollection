import sys
import math
import scipy
import operator
import fractions

def main():
    cCnt = int(sys.stdin.readline().strip())
    for i in range(cCnt):
        iCnt = int(sys.stdin.readline().strip())
        iList = [int(x.strip()) for x in sys.stdin.readline().split()]

        eatMin1 = 0
        maxDiff = 0
        for j in range(1, iCnt):
            diffVal = iList[j] - iList[j-1]
            if diffVal < 0:
                diffVal *= -1
                eatMin1 += diffVal
                if diffVal > maxDiff:
                    maxDiff = diffVal

        if maxDiff == 0:
            print("Case #{0}: {1} {2}".format(i+1, 0, 0))
            continue

        eatMin2 = 0
        for j in range(iCnt-1):
            eatMin2 += min([iList[j], maxDiff])

        print("Case #{0}: {1} {2}".format(i+1, eatMin1, eatMin2))

    return 0

main()
