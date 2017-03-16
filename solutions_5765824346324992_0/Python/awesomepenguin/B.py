def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a*b / gcd(a, b)

def lcmm(a):
    b = 1
    for i in a:
        b = lcm(b, i)
    return b

t = int(raw_input())

for qq in xrange(1, t+1):

    b, n = map(int, raw_input().split())
    ms = map(int, raw_input().split())

    remaining = [0] * len(ms)
    
    if n > b:
        l = lcmm(ms)
        people = sum([l / m for m in ms])
        n = n % people
        if n == 0: n = people
#        print people, n

#    if n > b:
#        rate = sum([1.0/m for m in ms])
#        time = int((n -b)/ rate)
#        #time = 448257420
#    
#        num = [int(time) / m for m in ms]
#        end = [num[i] * ms[i] for i in xrange(len(num))]
#        endt = max(end)
#    
#        n = n - sum(num)
#        into = [endt - a for a in end]
#        remaining = [ms[i] - a if a > 0 else a for a in into]
#        n = n - sum([1 for r in remaining if r > 0])
#    
#        print rate, time
#        print num
#        print end, endt
#        print remaining, n

    while n > 1:
        i, a = min(enumerate(remaining), key = lambda x: (x[1], x[0]))
        remaining = [r - a for r in remaining]
        remaining[i] = ms[i]
        n = n-1

#    print remaining
    ans, _ = min(enumerate(remaining), key=lambda x: x[1])

    print 'Case #%d: %d' % (qq, ans+1)

