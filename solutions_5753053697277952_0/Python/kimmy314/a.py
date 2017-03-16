# int(fInput.readline())
# fInput.readline().rstrip()
# [int(s) for s in str.split(fInput.readline().rstrip(),' ')]
# result = ' '.join(str(result[n]) for n in range(N))
import sys
import math
import numpy # http://www.numpy.org/
import string
import tkinter as tk
from tkinter.filedialog import askopenfilename

def debug(*args):
    print(" ".join(str(arg) for arg in args))
    return

root = tk.Tk()
root.withdraw()

filename = askopenfilename()
fInput = open(filename, 'r')
fOutput = open(filename.replace(".in", ".txt"), 'w+')

T = int(fInput.readline())

for t in range(T):
    N = int(fInput.readline())
    P = [int(s) for s in str.split(fInput.readline().rstrip(),' ')]
    result = []
    numP = sum(P)
    if N == 2:
        while numP > 0:
            result.append('AB')
            numP -= 2

    else:
        while numP > 0:
            maxP = [i for i, x in enumerate(P) if x == max(P)]
            if len(maxP) == 1:
                if numP % 2 == 0:
                    P[maxP[0]] -= 2
                    result.append(string.ascii_uppercase[maxP[0]] + string.ascii_uppercase[maxP[0]])
                else:
                    P[maxP[0]] -= 1
                    result.append(string.ascii_uppercase[maxP[0]])
            else:
                if numP % 2 == 0:
                    P[maxP[0]] -= 1
                    P[maxP[1]] -= 1
                    result.append(string.ascii_uppercase[maxP[0]] + string.ascii_uppercase[maxP[1]])
                else:
                    P[maxP[0]] -= 1
                    result.append(string.ascii_uppercase[maxP[0]])
                    
            numP = sum(P)

    result = ' '.join(str(result[n]) for n in range(len(result)))
    print('Case #{}: {}'.format(t+1, result))
    fOutput.write('Case #{}: {}\n'.format(t+1, result))

fInput.close()
fOutput.close()
