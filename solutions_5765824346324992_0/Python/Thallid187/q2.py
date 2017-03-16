import simpy

#lcm code taken from http://www.enrico-franchi.org/2010/09/nice-functional-lcm-in-python.html
from fractions import gcd
def lcm(numbers):
    return reduce(lambda x, y: (x*y)/gcd(x,y), numbers, 1)


f = open('B-small-attempt1.in', 'r')
o = open('out.txt', 'w')
T = f.readline()
T = int(T)
for t in range(1, T+1):
    n = f.readline()
    m = f.readline()
    m = m.split()
    n = n.split()
    n = map(int, n)
    M = map(int, m)

    B= n[0]
    N = n[1]

    endTimes = [0] * B

    stop = False
    curr = 1
    barber = 0

    #Do a jump
    LCM = lcm(M)
    summ = 0
    for i in range(0, B):
        summ += LCM/M[i]
    nJumps = (N-1) // summ
    curr += nJumps * summ
    print B, N, nJumps, curr, LCM
    
    while (stop != True):
        earliest = endTimes[0]
        earliestPos = 0
        for i in range(0, B):
            if(endTimes[i] < earliest):
                earliest = endTimes[i]
                earliestPos = i
        
        if curr == N:
            barber = earliestPos + 1
            stop = True
        else:
            endTimes[earliestPos] += M[earliestPos]
            curr += 1


    outline = "Case #%d: %d\n" % (t, barber)
    o.write(outline)

o.close()

