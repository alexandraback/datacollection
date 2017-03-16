
import sys

T = int(sys.stdin.readline())

for i in range(T):
    B, N = [int(x) for x in sys.stdin.readline()[:-1].split(" ")]
    M = [int(x) for x in sys.stdin.readline()[:-1].split(" ")]

    Q = [0]*B
    N0 = N

    lst = []
    
    while True:
        while 0 in Q:
            lst.append(Q.index(0)+1)
            ind = Q.index(0)
            Q[ind] = M[ind]

        Q = [x-1 if x > 0 else 0 for x in Q]
        
        if Q == [0]*B:
            print "Case #%i: %i" % (i+1, lst[N0%len(lst)-1])
            break
