# Written in Python 3.3

import math
import sys

# Get the rest of the convex hull starting from point p

def hullfromC(p,XY,angle):

    # Determine the angles and distances to all remaining
    # points on the hull

    ab = [-1,10000000]
    d  = 0

def getconvexhull(XY):

    # Choose the first point on the hull to have the smallest X

    C = 0
    Xb = XY[0][0]
    for ii in range(len(XY)):
        if XY[ii][0] < XY[C][0]:
            C = ii
            Xb = XY[ii][0]

    angle = [0,0]
    C = [C]
    C = C.extend(hullfromC(C[0],XY,angle))
    return C

def findsol(N,XY):

    # Special cases. Remaining code fails if only one
    # tree in forest

    if (N <= 3):
        b = []
        for ii in range(N):
            b.append(0)
        return b

    #C = getconvexhull(XY)

    # For each log, remove the trees on one side of a line
    # connected to another tree (that is on the convex hull)

    b = []
    for ii in range(N):

        bc = N+1
        for jj in range(N):
            if (ii==jj):
                continue

            # Normal vector to connecting line
            
            n = [XY[ii][1]-XY[jj][1] , XY[jj][0]-XY[ii][0]]

            # Get points on one side of the line

            cnt = 0
            cnt2 = 0
            for kk in range(N):
                d  = n[0] * (XY[ii][0]-XY[kk][0])
                d += n[1] * (XY[ii][1]-XY[kk][1])
                if (d < 0):
                    cnt += 1
                if (d > 0):
                    cnt2 += 1

            if (cnt < bc):
                bc = cnt
            if (cnt2 < bc):
                bc = cnt2

        b.append(bc)
    return b

# Code for converting a string with lots of numbers
# separated by spaces into a list

def convertnums(s):

    a = []
    ii = 0
    for jj in range(len(s)):
        if s[jj]==' ':
            if (ii < jj):
                a.append(int(s[ii:jj]))
                ii = jj + 1
                
    a.append(int(s[ii:jj]))  # No space at end

    return a

# The main code section

fidi = open('C-small-attempt1.in','r')
fido = open('a.out','w')

T = fidi.readline()
T = int(T)

for ii in range(1,T+1):
    N = fidi.readline()
    N = int(N)

    XY = []
    for kk in range(N):
        tmp = fidi.readline()
        XY.append(convertnums(tmp))
        
    # Find the solution

    a = findsol(N,XY)

    # Show the output

    fido.write('Case #' + str(ii)+':'+'\n')
    print('Case #',str(ii),':')
    for kk in range(N):
        fido.write(str(a[kk])+'\n')
        print(str(a[kk]))

fidi.close()
fido.close()



