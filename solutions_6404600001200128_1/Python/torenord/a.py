
import sys

T = int(sys.stdin.readline())

for t in range(T):
    N = int(sys.stdin.readline())
    M = [int(x) for x in sys.stdin.readline()[:-1].split(" ")]
    L = [M[i] - M[i+1] for i in range(N-1) if M[i] > M[i+1]]

    Y = sum(L)

    if len(L) == 0:
        rate = 0
    else:
        rate = max(L)

    X = sum(min(x, rate) for x in M[:-1])
    
    print "Case #%i: %i %i" % (t+1, Y, X)
