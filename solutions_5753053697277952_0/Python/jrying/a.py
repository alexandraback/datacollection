import sys
import fileinput
import re

#fileio
# fileName = 'A-large'
fileName = 'A-small-attempt0'
# fileName = 'A-test'
input = fileName + ".in"
output = fileName + ".out"

###
with open(input) as fi, open(output, "w") as fo:
    count = 0
    for line in fi.readlines()[2::2]:
        arr = map(int, line.split())
        result = []
        ###
        while True:
            maxn = 0
            maxes = []
            for i in range(len(arr)):
                if arr[i] > maxn:
                    maxn = arr[i]
                    maxes = [i]
                elif arr[i] == maxn:
                    maxes.append(i)
            if maxn == 0: break
            else:
                l = min(maxn, 2)
                if len(maxes) == 1 or len(maxes) == 3:
                    result.append(chr(ord('A') + maxes[0])*l)
                    arr[maxes[0]] -= l
                else:
                    result.append(chr(ord('A') + maxes[-1]) + chr(ord('A') + maxes[-2]))
                    arr[maxes[-1]] -= 1
                    arr[maxes[-2]] -= 1
            print arr, maxes, maxn, l
        result = " ".join(result)
        ###
        #normal
        count += 1
        resultStr = "Case #"+str(count)+": "+str(result)
        print resultStr
        fo.write(resultStr+'\n')
