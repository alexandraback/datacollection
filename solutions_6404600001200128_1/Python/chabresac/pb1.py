

def readFile(filename):
    with open(filename, 'r') as myfile:
        # First line is the smax
        text = myfile.readline()[:-1]#
        i = 1
        for line in myfile:
            line = myfile.readline()
            # Read the line in a list
            line = line[:-1]
            L = [ int(e) for e in line.split(' ')]
            #print(L)

            # Give the line without \n
            # solve the problem
            res1 = solve1(L)
            res2 = solve2(L)
            print("Case #{}: {} {}".format(i, res1, res2))
            i += 1


def lineToList(line):
    for i in range(len(line)):
        if line[i] == ' ':
            n = i+1
    numbers = line[n:]
    l = []
    for e in numbers:
        l.append(int(e))
    return l


def solve1(mush):
    res = 0
    s = mush[0]
    for e in mush[1:]:
        res += max(s-e, 0)
        s = e
    return res

def solve2(mush):
    M = 0
    res = 0
    s = mush[0]
    for e in mush:
        if s > e:
            M = max(s-e, M)
        s = e
    M = max(mush[-2]-mush[-1], M)
    #print(M)
    for e in mush[:-1]:
        res += min(e, M)
    return res

if __name__ == "__main__":
    filename = "A-large.in"
    #filename = "test.txt"
    readFile(filename)
