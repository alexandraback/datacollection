import sys, os, pdb

sys.setrecursionlimit(5000)

#infile = open('input')
infile = sys.stdin

def read_array(vtype):
    line = infile.readline()
    return [vtype(v) for v in line.split(' ')]

def get_rank(arr, i, time):
    rank = 0
    for j in xrange(len(arr)):
        v = arr[j]
        count = time / v
        if j < i:
            rank += (count + 1)
        else:
            rank += (count + 1)
            if count * v == time:
                rank -= 1
    return rank

def in_line(arr, i, k):
    left = 0
    right = k
    while left <= right:
        cur = (left + right) / 2
        time = cur * arr[i]
        rank = get_rank(arr, i, time)
        if rank == k:
            return True
        if rank > k:
            right = cur - 1
        else:
            left = cur + 1
    return False

def solve(arr, k):
    for i in xrange(len(arr)):
        if in_line(arr, i, k):
            return i+1
        
    raise Exception('No found!')

if __name__ == '__main__':
    T = int(infile.readline())
    for case in xrange(T):
        B, N = read_array(int)
        arr = read_array(int)
        ans = solve(arr, N-1)
        print 'Case #%d: %d' % (case + 1, ans)
