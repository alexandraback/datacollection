# Hello World program in Python
import sys
from math import ceil

global barbers

def totalServed(time):
    t = 0
    for x in barbers:
        t += int(ceil(1.0 * (time + 1) / x))
    return t
    
def binSearch(a, b, n):
    if a == b:
        return a
    x = int(ceil((b + a) / 2.0))
    if (totalServed(x) < n):
        return binSearch(x, b, n)
    else:
        return binSearch(a, x - 1, n)
        
cases = int(sys.stdin.readline())
for i in range(1, cases + 1):
    s = sys.stdin.readline().split()
    b = int(s[0])
    n = int(s[1])
    global barbers
    barbers = sys.stdin.readline().split()
    barbers = [int(x) for x in barbers]
    if (b > n):
        print "Case #%d: %d" % (i, n)
    else:
        x = 1
        while (totalServed(x) < n):
            x *= 2
        x = binSearch(x /2, x, n)
        n -= totalServed(x)
        for a in range(0, len(barbers)):
            if ((x + 1) % barbers[a] == 0):
                n -= 1
                if (n == 0):
                    print "Case #%d: %d" % (i, a + 1)
                    break