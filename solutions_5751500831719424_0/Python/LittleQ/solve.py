import gcj
import sys

def word2tuple(word):
    result = []
    last = word[0]
    n = 0
    
    for i in list(word):
        if i != last:
            result.append(n)
            n = 0
        last = i
        n += 1

    result.append(n)


    return tuple(result)

def allSameLength(l):
    l0 = len(l[0])
    for i in l:
        if len(i) != l0: return False
    return True

def getCenter(numberlist):
    MIN = 10000000

    for point in numberlist:
        min = sum(map(lambda x: abs(x-point), numberlist))
        if min < MIN: MIN = min

    return MIN

def sameString(stringlist):
    first = getOrdered(stringlist[0])
    
    for s in stringlist[1:]:
        if first != getOrdered(s): return False

    return True

def getOrdered(s):
    result = [ s[0] ]
    last = s[0]

    for i in s[1:]:
        if i != last:
            result.append(i)
        last = i

    return result
    

def main():
    IN = gcj.FileWrapper(open(sys.argv[1]))

    N = IN.getInt()

    for nono in range(N):
        cases = IN.getInt()
        inputs = []

        for nono2 in range(cases):
            inputs.append(IN.getWords()[0].strip())


        dis = map(word2tuple, inputs)


        if not allSameLength(dis):
            # no match
            gcj.printCase("Fegla Won")
            continue
        elif not sameString(inputs):
            gcj.printCase("Fegla Won")
            continue


        wordlen = len(dis[0])
        SUM = 0

        for idx in range(wordlen):
            SUM += getCenter(map(lambda d: d[idx], dis))

        gcj.printCase( SUM )
            

if __name__ == '__main__':
    main()
