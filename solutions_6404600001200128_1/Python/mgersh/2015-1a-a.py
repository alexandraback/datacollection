import string
import math

testcase = open('testcase', 'r')
num_cases = int(string.strip(testcase.readline()))


def do_calc(foo):
    n = int(string.strip(testcase.readline()))
    items = map(int, string.split(string.strip(testcase.readline())))
    y = 0
    z = 0
    lasti = items[0]
    biggest_drop = 0
    for i in items:
        drop = lasti - i
        if drop > 0:
            y += drop
        if drop > biggest_drop:
            biggest_drop = drop
        lasti = i
    for i in items[:-1]:
        z += min([biggest_drop, i])
    print "Case #"+str(foo)+": "+str(y)+" "+str(z)

for i in xrange(1, num_cases+1):
    do_calc(i)
