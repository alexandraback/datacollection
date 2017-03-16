__author__ = 'jin-yc10'

import sys
sys.stdout = open('1.out', 'w')

s = """46
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1
3
2 2 1
3
4 4 1
3
2 2 2
3
3 1 4
3
4 1 4
3
2 2 3
3
4 3 2
3
1 1 1
2
3 3
3
2 2 4
3
3 2 3
3
3 1 2
3
4 2 3
3
3 1 3
3
2 1 2
3
4 2 2
3
3 4 1
3
1 3 2
3
2 3 4
3
4 1 3
3
3 2 1
3
1 2 3
3
2 4 2
3
1 3 4
3
4 3 1
3
3 4 2
3
2 3 3
3
2 4 3
3
3 3 2
3
3 2 4
3
2 1 3
3
1 2 2
3
3 3 3
3
1 3 3
3
1 4 4
2
1 1
2
4 4
3
1 4 3
3
2 1 1
3
3 3 1
3
1 2 1
3
2 3 2
""".split('\n')
# Case #1: AB BA
# Case #2: AA BC C BA
# Case #3: C C AB
# Case #4: BA BB CA

def check(nn):
    ss = sum(nn)
    for xx in nn:
        if xx > ss/2:
            print xx, nn
            return False
    return True

t = int(s[0])
alphabet = [str(unichr((ord('A')+i))) for i in xrange(26)]
# print alphabet
for i in xrange(t):
    p = int(s[2*i+1])
    n = [int(x) for x in s[2*i+2].split()]
    total = sum(n)
    # print p,n
    seq = []
    while total > 0:
        m = max(n)
        if m == 1:
            mi = [ii for ii, jj in enumerate(n) if jj == m]
            special = ''
            for j in mi[:-2]:
                seq += [alphabet[j]]
            for j in mi[-2:]:
                special += alphabet[j]
            seq += [special]
            # print "1", special, n
            break
        mi = [ii for ii, jj in enumerate(n) if jj == m]
        for j in mi[:-2]:
            seq += [alphabet[j]]
            total -= 1
            n[j] -= 1
            # if not check(n):
            #     print 'error'
        special = ''
        for j in mi[-2:]:
            special += alphabet[j]
            n[j] -= 1
        seq += [special]
        # print n
    print "Case #%d:" % (i+1),
    for j in seq:
        print j,
    print ''