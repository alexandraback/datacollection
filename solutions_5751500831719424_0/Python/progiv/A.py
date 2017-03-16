
import math, sys
if len(sys.argv) > 1:
    inFile = sys.argv[1]
else:
    inFile = "in.txt"
inf = open(inFile, "r")
ouf = open("out.txt","w")

def close_files():
    inf.close()
    ouf.close()

printcounter = 0
def printstr(a):
    global printcounter
    printcounter +=1
    ouf.write('Case #%d: %s\n' % (printcounter,a))

def int2(str):
    return int(str, 2)
def bitsCount(number):
    return bitsCount(number & number-1) + 1 if number>0 else 0
def solvetest():
    n = int(inf.readline())
    a = [inf.readline().strip() for i in range(n)]
    b = [0 for i in range(n)]
    k = 0;
    answer = 0
    while b[0] < len(a[0]):
        counts = [0 for i in range(n)]
        while b[0]< len(a[0])-1 and a[0][b[0]] == a[0][b[0]+1]:
            counts[0] += 1
            b[0] += 1
        for i in range(1, n):
            if b[i] >= len(a[i]) or a[i][b[i]] != a[0][b[0]]:
                printstr("Fegla Won")
                return
            while b[i]< len(a[i]) and a[i][b[i]] == a[0][b[0]]:
                b[i] += 1
                counts[i] += 1
        b[0]+=1
        counts[0]+=1
        best = 1000000000
        #print (a, b, counts)
        for num in range(min(counts), max(counts)+1):
            cur = sum([abs(it - num) for it in counts])
            if best > cur:
                best = cur
        answer += best
    for i in range(1, n):
        if b[i]< len(a[i]):
            printstr("Fegla Won")
            return
    printstr(str(answer))

testnum = int(inf.readline())
for test in range(testnum):
        solvetest()
close_files()
