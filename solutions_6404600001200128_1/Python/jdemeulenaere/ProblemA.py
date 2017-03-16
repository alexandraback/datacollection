import math

data = open("input/problema.txt")
nb_cases = int(data.readline())

for z in xrange(nb_cases):
    print "Case #%d:" % (z + 1),
    N = int(data.readline())
    x = [int(x) for x in data.readline().split(" ")]

    last = x[0]
    total = 0
    max_rate = 0
    for i in xrange(1, len(x)):
        if x[i] < last:
            total += last - x[i]
            max_rate = max(max_rate, last - x[i])
        last = x[i]

    last = x[0]
    total2 = 0
    for i in xrange(1, len(x)):
        if last < max_rate:
            total2 += last
        else:
            total2 += max_rate
        last = x[i]

    print total, total2