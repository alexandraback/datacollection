
from itertools import *
import sys

debug = True

def log(*argv):
    if debug:
        print " ".join(imap(str, argv))

def main(f, case):
    a = int(f.readline())
    for i in range(1,5):
        if i == a:
            l1 = f.readline().split()
        else:
            f.readline()
    a = int(f.readline())
    for i in range(1,5):
        if i == a:
            l2 = f.readline().split()
        else:
            f.readline()
    s = [x for x in l1 if x in l2]
    if len(s) == 0:
        print "Case #" + str(case) + ": Volunteer cheated!"
    elif len(s) == 1:
        print "Case #" + str(case) + ":", s[0] 
    else:
        print "Case #" + str(case) + ": Bad magician!"



with open(sys.argv[1]) as f:
    N = int(f.readline())
    for i in xrange(N):
        main(f, i+1)
