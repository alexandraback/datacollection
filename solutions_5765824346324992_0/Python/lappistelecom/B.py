def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

def gcd(*numbers):
    from fractions import gcd
    return reduce(gcd, numbers)

def lcm(*numbers):
    def lcm(a, b):
        return (a * b) // gcd(a, b)
    return reduce(lcm, numbers, 1)

class Barber:
    def __init__(self, barber, mi, time):
        self.barber = barber
        self.mi = mi
        self.time = time

    def __cmp__(self, obj):
        if self.time > obj.time:
            return 1
        if self.time < obj.time:
            return -1
        if self.barber > obj.barber:
            return 1
        if self.barber < obj.barber:
            return -1
        return 0

    def __str__(self):
        return 'Barber %d with time %d and speed %d' % (self.barber, self.time, self.mi)

T = readint()
for t in range(T):

    B, N = readarray(int)
    M_i = readarray(int)

    #if N <= B:
    #    l = list()
    #    for index, mi in enumerate(M_i):
    #        l.append(Barber(index+1,mi,0))
    #    sorted(l)
    #    print 'Case #%i: %d'%((t+1), l[N-1].barber)
    #    continue

    ppcm = lcm(*M_i)
    
    res = 0
    #print ppcm
    tmin = min(M_i)
    Nmax = tmin * N
    liste = list()
    for i, mi in enumerate(M_i):
        counter = 0
        while counter < ppcm:
            liste.append(Barber(i+1,mi,counter))
            counter += mi
    N_mod = (N-1) % len(liste)
    liste = sorted(liste)
    print 'Case #%i: %d'%((t+1), liste[N_mod].barber)
