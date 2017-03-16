import sys
import heapq

# takes M_k minutes to cut someone's hair
def run(B,N,M):
    def val(t):
        served = sum((t + M[i]-1) // M[i] for i in range(B))
        if served >= N:
            return 1, 'whatever1'
        if served < N-B:
            return -1, 'whatever2'
        freebar = [i for i in range(B) if t % M[i] == 0]
        if served + len(freebar) >= N:
            return 0, freebar[N-1-served] + 1
            # this is 1 indexed barber number, and the answer
        else:
            return -1, 'whatever3'

    # the minute at which you get served
    low = 0
    high = 10**14+3
    while True:
        mid = (low + high) // 2
        a,b = val(mid)
        if a == 1:
            high = mid
            continue
        if a == -1:
            low = mid
            continue
        return b

fin = open(sys.argv[1])
T = int(fin.readline().strip())
for i in range(1,T+1):
    B,N = [int(x) for x in fin.readline().strip().split()]
    M = [int(x) for x in fin.readline().strip().split()]
    ans = run(B,N,M)
    print('Case #%d: %s' % (i, ans))
