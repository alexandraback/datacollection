import sys

def solve(words, N):
    p = [0]*N
    edit = 0
    while p[0] < len(words[0]):
        letter = words[0][p[0]]
        num = [0]*N
        for i in xrange(N):
            while p[i] < len(words[i]) and letter == words[i][p[i]]:
                num[i] += 1
                p[i] += 1
            if num[i] == 0:
                return -1
        num.sort()
        mid = num[N/2]
        for i in xrange(N):
            edit += abs(num[i] - mid)
    for i in xrange(N):
        if p[i] != len(words[i]):
            return -1
    return edit

if __name__ == '__main__':
    f = sys.stdin
    T = int(f.readline())
    for i in xrange(1, T+1):
        N = int(f.readline())
        words = []
        for j in xrange(N):
            words.append(f.readline().strip())
        ret = solve(words, N)
        if ret == -1:
            print "Case #%d: Fegla Won" % i
        else:
            print "Case #%d: %d"  % (i, solve(words, N))
