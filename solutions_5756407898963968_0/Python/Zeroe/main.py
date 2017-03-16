import string
import sys
import math
import itertools
import operator
import cPickle
from collections import Counter

class Tee:
    def __init__(self, file):
        self.file = file
        
    def write(self, str):
        sys.stdout.write(str)
        self.file.write(str)

    def close(self):
        self.file.close()

def getRowElements(r):
    e = [[int(x) for x in fin.readline().split()] for _ in xrange(4)]
    return e[r-1]

#name = "test"
name = "A-small-attempt0"

fin = open(name+".in", "r")
fout = open(name+".out", "w")
fout = Tee(fout)

T = int(fin.readline())

for t in range(1,T+1):
    a0 = int(fin.readline())
    r0 = getRowElements(a0)
    
    a1 = int(fin.readline())
    r1 = getRowElements(a1)
    
    e = list(set(r0).intersection(set(r1)))

    r = ""
    if not e:
        r = "Volunteer cheated!"
    elif len(e) > 1:
        r = "Bad magician!"
    else:
        r = e[0]

    print >> fout, "Case #{}: {}".format(t, r)

