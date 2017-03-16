import sys, os, pdb

sys.setrecursionlimit(5000)

#infile = open('input')
infile = sys.stdin

def read_array(vtype):
    line = infile.readline()
    return [vtype(v) for v in line.split(' ')]

def solve(arr):
    a = 0
    b = 0
    rate = 0
    for i in xrange(len(arr) - 1):
        a += max(0, arr[i] - arr[i+1])
        rate = max(rate, arr[i] - arr[i+1])

    for i in xrange(len(arr) - 1):
        b += min(arr[i], rate)

    return a, b

if __name__ == '__main__':
    T = int(infile.readline())
    for case in xrange(T):
        n = infile.readline()
        arr = read_array(int)
        a, b = solve(arr)
        print 'Case #%d: %d %d' % (case + 1, a, b)
            
            
