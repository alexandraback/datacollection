import sys
import itertools
import numpy as np

#takes some minutes to run


# open input files and read in into lines
filename = "input.txt"
inputFromFile=True
if inputFromFile: inp = open(filename)
else: inp=sys.stdin

# Precomputation


def pre(s):
    return [c for (c,_) in itertools.groupby(s) ]


def solveTestCase(ls):
    N=len(ls)
    ref=pre(ls[0])
    n=len(ref)

    groups = []
    uniquekeys = []



    matrix = np.zeros((N,n))
    for i in range(N):
        groups = []
        uniquekeys = []

        for k, g in itertools.groupby(ls[i]):
            groups.append(len(list(g)))      # Store group iterator as a list
            uniquekeys.append(k)
        if(uniquekeys!=ref): return "Fegla Won"
        matrix[i,:]=groups
    count=0
    median=np.median(matrix,0)
    #print matrix
    #print median
    for i in range(n):
        med = median[i]
        for j in range(N):
            count+=abs(matrix[j][i]-int(med))

    return str(int(count))


T =int(inp.readline())

for t in range(1,T+1):
    N=int(inp.readline())
    ls=[]
    for i in range(N):
        s=inp.readline().strip()
        ls.append(s)
    print "Case #%d: %s"  % (t,solveTestCase(ls))
