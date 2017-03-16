def maxIndex(PiList):
    maxIndex = []
    currMax = -1
    for i in range(len(PiList)):
        if PiList[i] > currMax:
            currMax = PiList[i]
            maxIndex = [i]
        elif PiList[i] == currMax:
            maxIndex.append(i)
    return maxIndex

def intToChar(i):
    return str(chr(i+65))

def indexesOf(PiList, i):
    res = []
    for x in range(len(PiList)):
        if PiList[x] == i:
            res.append(x)
    return res

def solve(N, PiList, x, res):
    total = sum(PiList)
    print total
    evacplan = []
    while total > 2:
        index = maxIndex(PiList)
        step = ""
        step += intToChar(index[0])
        PiList[index[0]] -= 1
        total -= 1
        if len(index) > 1 and total > 2:
            step += intToChar(index[1])
            PiList[index[1]] -= 1
            total -= 1
        evacplan.append(step)
        print index
        print total
        print evacplan
    print evacplan
    lastStep = ""
    index = maxIndex(PiList)
    lastStep += intToChar(index[0])
    PiList[index[0]] -= 1
    index = maxIndex(PiList)
    lastStep += intToChar(index[0])
    evacplan.append(lastStep)
    print evacplan
    res.write("Case #{}: {}\n".format((x + 1), ' '.join(evacplan)))


def main():
    f = open("C://CodeJam/a3.in", 'r')
    res = open("C://CodeJam/a3.out", 'w')
    T = int(f.readline())
    for x in range(T):
        N = int(f.readline())
        PiList = f.readline().split()
        PiList = map(int, PiList)
        print N
        print PiList
        solve(N, PiList, x, res)
    f.close()
    res.close()

if __name__ == "__main__":
    main()
