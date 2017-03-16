import sys

args = sys.argv

if len(args) == 2:
    f = open(args[1],'r')
    of = open('output.txt','w')
    breakFlag = False
    num = 0
    numCalculated = False
    i = -1
    while not breakFlag:
        l = f.readline()
        if not numCalculated:
            num = int(l.strip())
            numCalculated = True
            i = 0
        elif i < num:
            l = l.strip()
            l1 = f.readline()
            B = int(l.split(' ')[0])
            N = int(l.split(' ')[1])
            barbs = []
            barbDict = {}
            y = 1
            for x in l1.split(' '):
                barbs.append(int(x))
                barbDict[(int(x),y)] = 0
                y = y + 1
            k = list(barbDict.keys())
            k.sort()
            minsTillNext = []
            if N <= B:
                of.write('Case #'+str(i+1)+': ' + str(N) + '\n')
                print('Case #'+str(i+1)+': ' + str(N) + '')
            else:
                newN = N - B
                currMins = 0
                for x in k:
                    minsTillNext.append(x)
                rem = newN - 1
                while rem > 0:
                    nextBarb = minsTillNext[0]
                    currMins = nextBarb[0]
                    yflag = False
                    newMinsTillNext = (minsTillNext[0][0] + barbs[minsTillNext[0][1] - 1] , minsTillNext[0][1])
                    minsTillNext[0] = newMinsTillNext
                    j = 0
                    while not yflag:
                        if minsTillNext[j][0] > minsTillNext[j+1][0]:
                            t = minsTillNext[j]
                            minsTillNext[j] = minsTillNext[j+1]
                            minsTillNext[j+1] = t
                        elif minsTillNext[j][0] == minsTillNext[j+1][0]:
                            if minsTillNext[j][1] > minsTillNext[j+1][1]:
                                t = minsTillNext[j]
                                minsTillNext[j] = minsTillNext[j+1]
                                minsTillNext[j+1] = t
                        else:
                            yflag = True
                            break;
                        if j == B-2:
                            yflag = True
                            break;
                        j = j + 1
                    rem = rem - 1
                    tflag = True
                    tillNow = 0
                    for y in barbs:
                        if currMins % y != 0:
                            tflag = False
                            break;
                        else:
                            tillNow = tillNow + int(currMins/y)
                    if tflag:
                        mult = int(rem/tillNow)
                        if mult > 0:
                            for j in range(B):
                                newMinsTillNext = (minsTillNext[j][0] + currMins*mult , minsTillNext[j][1])
                                minsTillNext[j] = newMinsTillNext
                        rem = rem - tillNow*mult
                of.write('Case #'+str(i+1)+': ' + str(minsTillNext[0][1]) + '\n')
                print('Case #'+str(i+1)+': ' + str(minsTillNext[0][1]) + '')
            i = i + 1
        else:
            breakFlag = True
    of.flush()
    of.close()
    f.close()

sys.exit()


"""of.write('Case #'+str(i+1)+': NO\n')
print('Case #'+str(i+1)+': NO')"""
