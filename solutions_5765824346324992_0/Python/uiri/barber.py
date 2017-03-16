import sys, math

stdin = sys.stdin.readlines()
cases = int(stdin.pop(0))
for case in xrange(1,cases+1):
    b, n = stdin.pop(0).strip().split(' ')
    m = stdin.pop(0).strip().split(' ')
    b = int(b)
    n = int(n)
    times = []
    next_ = range(b-1,-1,-1)
    for i in xrange(b):
        m[i] = int(m[i])
        times.append(0)
    comm_multiple = 1
    for i in xrange(b):
        k = m[i]
        j = 2
        while k > 1:
            if comm_multiple%k == 0:
                break
            while j < k and j%k != 0:
                j += 1
            comm_multiple *= j
            k /= j
    s = 0
    for i in xrange(b):
        s += comm_multiple/m[i]
    n = n%s
    if not n:
        n = s
    j = 1
    while j < n:
        i = next_.pop()
        times[i] += m[i]
        k = 0
        l = len(next_)
        while k<l and times[i] <= times[next_[k]]:
            if times[i] == times[next_[k]] and i > next_[k]:
                break
            k += 1
        next_.insert(k, i)
        j += 1
    print "Case #"+str(case)+":", next_.pop() + 1
