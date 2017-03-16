
import sys

def read():
    return sys.stdin.readline().strip()

def first_count(readings):
    total = 0
    for i in xrange(len(readings) - 1):
        a, b = readings[i], readings[i+1]
        if b < a:
            total += a - b
    return total

def second_count(readings):
    max_rate = 0
    for i in xrange(len(readings) - 1):
        a, b = readings[i], readings[i+1]
        if b < a:
            rate = a - b
            if max_rate is None or rate > max_rate:
                max_rate = rate

    total = 0
    for i in xrange(len(readings) - 1):
        total += min(max_rate, readings[i])
    return total

num_cases = int(read())
for i in xrange(num_cases):
    read()
    readings = [int(x) for x in read().split(" ")]

    print "Case #%d: %s %s" % (i + 1, first_count(readings), second_count(readings))

