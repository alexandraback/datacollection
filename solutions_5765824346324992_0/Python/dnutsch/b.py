#1/usr/bin/py

import fractions

def lcm(a,b):
    return abs(a*b) / fractions.gcd(a,b)

fin = open("B-small-attempt1.in", "r")
fout = open("B-small.out", "w")

T = int(fin.readline().strip())

for t in xrange(0,T):
    B,N = [int(x) for x in fin.readline().strip().split(' ')];
    minutes = [int(x) for x in fin.readline().strip().split(' ')];

    cm = minutes[0]
    for b in xrange(1,B):
        cm = lcm(cm,minutes[b])

    haircuts = 0
    for b in xrange(0,B):
        haircuts += cm //minutes[b]

    counters = [0] * B
    elapsed = 0
    last = -1

    min_time = 0

    n_sub = N % haircuts
    if n_sub == 0:
        n_sub = haircuts

    for n in xrange(0,n_sub):
        min_time = min(counters)
        if (min_time > 0):
            elapsed += min_time
            for b in xrange(0,B):
                counters[b] -= min_time
        for b in xrange(0,B):
            if counters[b] == 0:
                if minutes[b] > min_time:
                    min_time = minutes[b]
                counters[b] = minutes[b]
                last = b
                break;



    print "Case #{}: {}".format(t+1, last+1)
    fout.write("Case #{}: {}\n".format(t+1, last+1))


