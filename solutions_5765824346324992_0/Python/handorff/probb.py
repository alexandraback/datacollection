import fractions

def lcm(a, b):
    return a * b / fractions.gcd(a, b)

def gcd(lst):
    if len(lst) == 0:
        raise ValueError
    elif len(lst) == 1:
        return lst[0]
    elif len(lst) == 2:
        return lcm(lst[0], lst[1])
    else:
        ret = lcm(lst[0], lst[1])
        for elt in lst[2:]:
            ret = lcm(ret, elt)
        return ret

def solve(b, n, m):
    g = gcd(m)
    cycle_length = 0

    for i in xrange(g):
        for m_k in m:
            if i % m_k == 0:
                cycle_length += 1
    position = n % cycle_length

    if position == 0:
        position = cycle_length

    for i in xrange(g):
        for (j, m_k) in enumerate(m):
            if i % m_k == 0:
                position -= 1
            if position == 0:
                return j + 1


t = int(raw_input())
test_cases = []

for i in xrange(t):
    b, n = map(int, raw_input().split(' '))
    m = map(int, raw_input().split(' '))
    test_cases.append((b, n, m))

for i in xrange(t):
    b, n, m = test_cases[i]
    print "Case #%d: %d" % (i + 1, solve(b, n, m))
