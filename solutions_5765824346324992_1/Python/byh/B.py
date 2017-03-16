'''
Created on Apr 17, 2015

@author: billyanhuang
'''
fin = open('B-large.in', 'r')
fout = open('B-large.out', 'w')

def small(B, nvals, maxi):
    min = -maxi-1
    id = 0
    for i in range(B):
        if (nvals[i] < min) or (min < -maxi):
            min = nvals[i]
            id = i
    return id

T = int(fin.readline())
for j in range(T):
    inp = fin.readline().split()
    B = int(inp[0])
    N = int(inp[1])
    inp = fin.readline().split()
    vals = [int(inp[i]) for i in range(B)]
    maxi = 0
    for i in range(B):
        if vals[i] > maxi:
            maxi = vals[i]
    
    hsum = float(0)
    for i in range(B):
        hsum += float(1)/float(vals[i])
    Tapp = int(float(N)/hsum)
    Tapp = max(0, Tapp - maxi)
    
    curN = 1
    for i in range(B):
        curN += Tapp/vals[i]
    nvals = [-(Tapp%vals[i]) for i in range(B)]
    
    while curN < N:
        id = small(B, nvals, maxi)
        nvals[id] += vals[id]
        curN += 1
        #print curN
        #print nvals
    
    id = small(B, nvals, maxi)
    #print id+1
    #print "\n"
    fout.write("Case #" + str(j+1) + ": " + str(id + 1) + "\n")
    
    
    