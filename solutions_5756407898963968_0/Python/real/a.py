import sys, itertools, collections
sys.setrecursionlimit(10000)

read_ints = lambda: map(int, raw_input().split())
read_int  = input

def get():
    r = read_int()
    for i in xrange(4):
        t = read_ints()
        if i + 1 == r:
            ret = t
    return set(ret)

for no_t in xrange(1, read_int() + 1):
    possible = get() & get()
    if not possible:
        ans = 'Volunteer cheated!'
    elif len(possible) > 1:
        ans = 'Bad magician!'
    else:
        ans = list(possible)[0]

    print 'Case #%d: %s' % (no_t, ans)
