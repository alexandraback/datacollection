import sys
from collections import defaultdict
from fractions import gcd
from math import factorial

T = int(sys.stdin.readline())

case = 1
for case in range(1, T+1):
    N = int(sys.stdin.readline().strip())
    A = map(int, sys.stdin.readline().strip().split())
    s = []
    while sum(A) > 0:
        str = ''
        str += chr(A.index(max(A)) + ord('A'))
        A[A.index(max(A))] -= 1
        if sum(A) > 0 and 1.0 * max(A) / sum(A) > 0.5:
            str += chr(A.index(max(A)) + ord('A'))
            A[A.index(max(A))] -= 1
        if sum(A) > 0 and 1.0 * max(A) / sum(A) > 0.5:
            print "FAIL!!!!"
        s.append(str)
    print "Case #{0}:".format(case), " ".join(s)
        
        
