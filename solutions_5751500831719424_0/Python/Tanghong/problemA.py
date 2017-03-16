import sys

def solve(words, N):
    i = 0
    j = 0
    edit = 0
    while i < len(words[0]) and j < len(words[1]):
        letter = words[0][i]
        num1 = 0
        while i < len(words[0]) and letter == words[0][i]:
            num1 += 1
            i += 1
        num2 = 0
        while j < len(words[1]) and letter == words[1][j]:
            num2 += 1
            j += 1
        if num2 == 0:
            return -1
        edit += abs(num1 - num2)
    if i != len(words[0]) or j != len(words[1]):
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
