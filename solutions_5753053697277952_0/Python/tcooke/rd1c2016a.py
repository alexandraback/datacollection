# Written in Python 3.3

import math
import sys

def findsol(N):
    s = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

    out = ''

    S = 0
    for ii in N:
        S = S+ii

    l = 1
    for jj in range(S-2):

        # Find the maximum value

        m = 0
        mk = -1
        for kk in range(len(N)):
            if (N[kk]>m):
                m = N[kk]
                mk = kk

        # Output the senator

        out = out + s[mk]
        if (l==0):
            out = out + ' '
        l = 1 - l
        N[mk] = N[mk]-1

    if (l==0):
        out = out + ' '

    # The last two senators need to go out together

    mk = [-1,-1]
    for jj in range(len(N)):
        if N[jj]==1:
            out = out + s[jj]
        
    return out

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

fidi = open('A-small-attempt1.in','r')
fido = open('a.out','w')

T = fidi.readline()
T = int(T)

for ii in range(1,T+1):
    x = fidi.readline()
    N = convertnums(fidi.readline())
      
    # Find the solution

    a = findsol(N)

    # Show the output

    fido.write('Case #' +str(ii)+': '+a+'\n')
    print('Case #'+str(ii)+': '+a)

fidi.close()
fido.close()



