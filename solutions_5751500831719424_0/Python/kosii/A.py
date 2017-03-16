import itertools
import string

filename = 'A-small-attempt2'
inputfile = filename + '.in'
outputfile = filename + '.out'

resulttemplate = "Case #{t}: {res}\n"

def is_feasible(strings):
    return len(set(map(lambda s: ''.join(map(lambda (k, v): k, itertools.groupby(s))), strings))) == 1

def counter(s):
    return map(lambda (k,v): len(list(v)), itertools.groupby(s))

def median(data):
    """Return the median (middle value) of numeric data.

    When the number of data points is odd, return the middle data point.
    When the number of data points is even, the median is interpolated by
    taking the average of the two middle values:

    >>> median([1, 3, 5])
    3
    >>> median([1, 3, 5, 7])
    4.0

    """
    data = sorted(data)
    n = len(data)
    if n == 0:
        raise StatisticsError("no median for empty data")
    if n%2 == 1:
        return data[n//2]
    else:
        i = n//2
        return (data[i - 1] + data[i])/2


def abs(x): return x if x > 0 else -x

def absolute_distances_sum(f, ints):
    return sum(map(lambda x: abs(f - x), ints))

def smallest_abs_difference(ints):
    return min(xrange(101), key=lambda i: absolute_distances_sum(i, ints))


def rid_med(ints):
    return sum(ints)/len(ints)


with open(inputfile) as input, open(outputfile, 'w') as output:
    T = int(input.readline())
    for t in xrange(T):
        N = int(input.readline())
        strings = []
        for n in xrange(N):
            s = filter(lambda ch: ch in string.lowercase, input.readline())
            strings.append(s)

        if is_feasible(strings):
            asdddd = zip(*map(counter, strings))
            # print map(smallest_abs_difference, asdddd)
            output.write(resulttemplate.format(t=t+1, res=sum(map(lambda g: absolute_distances_sum(rid_med(g), g), asdddd))))
        else:
            output.write("Case #{t}: Fegla Won\n".format(t=t+1))

