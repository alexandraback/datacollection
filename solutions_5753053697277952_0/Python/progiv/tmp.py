import math
import sys
sys.setrecursionlimit(1000000)
inf = open("in.in", "r")
ouf = open('out.out','w')

def close_files():
        inf.close()
        ouf.close()

printcounter = 0
def printstr(a):
        global printcounter
        printcounter +=1
        print ('Case #%d: %s' % (printcounter,a), file=ouf)

def solvetest():
        n = int(inf.readline().strip())
        p = list(map(int, inf.readline().split()))
        s = sum(p)
        ans = []
        AA = ord('A')
        if s%2==1:
            mm = 0
            for i in range(n):
                if p[i]>p[mm]:
                    mm = i
            ans.append(chr(mm+AA))
            p[mm] -= 1
            s -= 1
            
        while s>0:
            mm1 = 0
            mm2 = 1
            for i in range(n):
                if p[i]>=p[mm1]:
                    mm2 = mm1
                    mm1 = i
                elif p[i]>=p[mm2]:
                    mm2 = i
            ans.append("{0}{1}".format(chr(mm1+AA), chr(mm2+AA)))
            p[mm1] -= 1
            p[mm2] -= 1
            s -= 2
        printstr(' '.join(ans))

testnum = int(inf.readline())
for test in range(testnum):
        solvetest()
close_files()

