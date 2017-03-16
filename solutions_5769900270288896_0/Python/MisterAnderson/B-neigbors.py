import sys
import numpy as np

def log(*args, sep=" ", end="\n", file= sys.stderr, flush= False):
    file.write(sep.join(str(a) for a in args) + end)
    if flush:
        file.flush()

def allLayouts(r, c, n):
    ln= r * c
    fmt= "{:0"+str(ln)+"b}"
    for i in range(2**ln):
        b= list(int(x) for x in fmt.format(i))
        if sum(b) == n:
            yield np.array(b).reshape((r,c,))

def rowUnhappiness(row):
    u= 0
    last= row[0]
    for cell in row[1:]:
        if last and cell:
            u+= 1
        last= cell
    return u

def unhappiness(arr):
    u= 0
    for i in range(arr.shape[0]):
        u+= rowUnhappiness(arr[i,:])
    for i in range(arr.shape[1]):
        u+= rowUnhappiness(arr[:,i])
    return u

def minUnhappiness(r, c, n):
    return min(unhappiness(arr) for arr in allLayouts(r, c, n))

if __name__ == "__main__":
    nCases= int(input())
    for iCase in range(1, nCases + 1):
        r, c, n= map(int, input().split())
        
        result= minUnhappiness(r, c, n)

        print("Case #{:d}: {:d}".format(iCase, result))
