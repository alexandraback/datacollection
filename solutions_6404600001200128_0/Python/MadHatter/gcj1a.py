import os

__author__ = 'dkopiychenko'

def nn(l):

    mm = 0
    for i in range(len(l) - 1):
        if l[i] - l[i+1] > mm:
            mm = l[i] - l[i+1]
    a = 0
    for i in range(len(l) - 1):
        a += min(mm, l[i])

    b = 0
    for i in range(len(l) - 1):
        b += max(l[i] - l[i+1], 0)
    return mm, b, a

with open(os.path.expanduser("~/Downloads/A-small-attempt0 (1).in")) as f:
    n = f.readline().strip('\n')
    print n
    lines = [x.strip('\n') for x in f.readlines()]
    counter = 1
    for i in range(len(lines)/2):
        n = int(lines[2*i])
        l = [int(g) for g in lines[2*i + 1].split(' ')]
        print 'Case #' + str(counter) + ': ' + str(nn(l)[1]) + ' ' + str(nn(l)[2])
        counter += 1