f_in = open('/Users/ctynan/Downloads/A-small-attempt0.in', 'r')
f_out = open('/Users/ctynan/Downloads/A-small.out', 'w')

T = int(f_in.readline())

for tst in range(T):
    N = int(f_in.readline().strip('\n'))
    m = f_in.readline().strip('\n').split(' ')
    m = map(lambda x: int(x), m)

    minOne, maxRate = 0, 0

    for i in range(N-1):
        minOne += max(0, m[i] - m[i+1])
        maxRate = max(maxRate, m[i] - m[i+1])

    minTwo = 0

    for i in range(N-1):
        minTwo += min(maxRate, m[i])

    f_out.write(("Case #%i: %i %i\n" % (tst+1, minOne, minTwo)))
