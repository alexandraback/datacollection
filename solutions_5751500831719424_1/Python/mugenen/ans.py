import sys
import collections

T = int(raw_input())
for t in xrange(1, T + 1):
    N = input()
    
    text = [raw_input().strip() for i in xrange(N)]
    
    cur = [0] * N
    L = map(len, text)
    result = 0
    fail = False
    while cur[0] < L[0]:
        char = text[0][cur[0]]
        temp = cur[:]
        for i in xrange(N):
            while cur[i] < L[i] and text[i][cur[i]] == char:
                cur[i] += 1
#            print i, text[i], text[i][cur[i]], char, cur[i]
#        print cur
#        print temp
#        result += abs((cur[0] - temp[0]) - (cur[1] - temp[1]))
        diff = [cur[i] - temp[i] for i in xrange(N)]
        diff.sort()
#        dz = diff[0]
#        print diff
        s = sum(diff)
        s2 = sum(diff)
        ii = 0
        for i in xrange(N):
            s2 -= (diff[i] - ii) * (N - 1 - i + 1)
            s2 += (diff[i] - ii) * (i)
            s = min(s, s2)
            ii = diff[i]
#        print s, diff
        result += s
#        for i in xrange(N):
#            diff[i] -= dz
#        print diff
        for i in xrange(N):
            if cur[i] - temp[i] == 0:
                print "Case #{0}: {1}".format(t, 'Fegla Won')
                fail = True
                break
        if fail:
            break
    if fail:
        continue
#        print cur
        #zero length
    for i in xrange(N):
        if cur[i] < len(text[i]):
            print "Case #{0}: {1}".format(t, 'Fegla Won')
            break
    else:
        print "Case #{0}: {1}".format(t, result)

