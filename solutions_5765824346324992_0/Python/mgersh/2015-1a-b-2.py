import string
import math

testcase = open('testcase', 'r')
num_cases = int(string.strip(testcase.readline()))


def do_calc(i):
    params = map(int, string.split(string.strip(testcase.readline())))
    b = params[0]
    n = params[1]
    n = n - 1
    barbers = map(int, string.split(string.strip(testcase.readline())))
    rollover = 1
    for bar in barbers:
        rollover *= bar
    rollover_served = []
    for bar in barbers:
        rollover_served.append(rollover/bar)
    customers = sum(rollover_served)
    n = n%customers
    time_done = [0]*b
    timestamp = 0
    for l in xrange(n+1):
        next_barber = time_done.index(min(time_done))
        if time_done[next_barber] == timestamp:
            time_done[next_barber] = timestamp + barbers[next_barber]
        else:
            timestamp = time_done[next_barber]
            time_done[next_barber] = timestamp + barbers[next_barber]

    print "Case #"+str(i)+": "+str(next_barber + 1)

for i in xrange(1, num_cases+1):
    do_calc(i)
