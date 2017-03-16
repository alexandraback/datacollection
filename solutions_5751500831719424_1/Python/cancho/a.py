from itertools import izip

T = int(raw_input())


def p(s):
    prev = s[0]
    cnt = 1
    a = []
    b = []
    for x in s[1:]:
        if prev == x:
            cnt += 1
        else:
            a.append(prev)
            b.append(cnt)
            prev = x
            cnt = 1
    a.append(prev)
    b.append(cnt)
    #print a, b
    return a, b


def test_A(A):
    a_t = A[0]
    return not any(a != a_t for a in A)


def answer(A, B):
    if not test_A(A):
        return 'Fegla Won'

    result = 0
    for l in izip(*B):
        l = sorted(l)
        med = l[len(l)/2]
        result += sum(abs(i - med) for i in l)
    return result


for t in xrange(1, T + 1):
    n = int(raw_input())
    s = []
    cur = [0] * n
    A, B = [], []
    for _ in xrange(n):
        s = raw_input()
        a, b = p(s)
        A.append(a)
        B.append(b)
    print 'Case #%d: %s' % (t, answer(A, B))

