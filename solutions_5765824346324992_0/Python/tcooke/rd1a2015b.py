# Written in Python 3.3

import math
import sys
import fractions

def findsol2(B,N,M):
    # Determine the times

    T = 0
    Tf = []
    for ii in range(B):
        Tf.append(0)

    for ii in range(N):
        # Choose the barber next to finish

        Tk = Tf[0]
        kk = 0
        for jj in range(B):
            if Tf[jj] < Tk:
                Tk = Tf[jj]
                kk = jj

        if (ii == N-1):
            return kk+1

        Tf[kk] += M[kk]

def findsol(B,N,M):

    # Determine the relative speed of barbers

    p = 1
    s = 0
    for ii in M:
        p *= ii
    for ii in M:
        s += p/ii
    g = fractions.gcd(p,s)
    p /= g
    s /= g

    R = []
    for ii in M:
        R.append([p,s*ii])
    
    # Determine the times for the easily determine values

    T = 0
    Tf = []
    N2 = N
    for ii in range(B):
        tmp = int((N2-B-1)*R[ii][0]/R[ii][1])
        Tf.append(tmp * M[ii])
        N -= tmp

    for ii in range(N):
        # Choose the barber next to finish

        Tk = Tf[0]
        kk = 0
        for jj in range(B):
            if Tf[jj] < Tk:
                Tk = Tf[jj]
                kk = jj

        if (ii == N-1):
            return kk+1

        Tf[kk] += M[kk]

def findsol3(B,N,M):

    # Determine the relative speed of barbers

    p = 1
    s = 0
    for ii in M:
        p *= ii
    for ii in M:
        s += p/ii
    g = fractions.gcd(p,s)
    p /= g
    s /= g

    R = []
    for ii in M:
        R.append([p,s*ii])
    print(R)

    # Now see how long it takes to complete N-1 haircuts,
    # and choose the one with the smallest remainder

    bTr = M[0]
    b = 0
    for jj in range(B):
        ii = B-1-jj
        tmp = R[ii][0] * N % R[ii][1]
        if (tmp == 0):
            tmp = R[ii][1]

        tmp = tmp * M[ii]/R[ii][1]
        if (tmp < bTr):
            bTr = tmp
            b = ii
        print(ii,tmp)

    return b+1  # 1 based

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

fidi = open('B-small-attempt2.in','r')
fido = open('a.out','w')

T = fidi.readline()
T = int(T)

for ii in range(1,T+1):
    tmp = fidi.readline()
    tmp = convertnums(tmp)
    B = tmp[0]
    N = tmp[1]

    M = fidi.readline()
    M = convertnums(M)
        
    # Find the solution

    a = findsol(B,N,M)

    # Show the output

    fido.write('Case #' + str(ii)+': '+str(a)+'\n')
    print('Case #',str(ii),': ',str(a))

fidi.close()
fido.close()



