import sys

inp = map(int, (' '.join(sys.stdin.read().splitlines())).split(' '))

N = inp[0]
for i in xrange(N):
    t = inp[1+i*34:35+i*34]
    n1, n2 = t[0]-1, t[17]-1
    r1 = t[1:17]
    r2 = t[18:]
    s1 = set(r1[n1*4:][:4])
    s2 = set(r2[n2*4:][:4])
    s = s1 & s2
    if len(s) == 1:
        r = str(list(s)[0])
    elif len(s) > 1:
        r = "Bad magician!"
    else:
        r = "Volunteer cheated!"
    print "Case #%d: %s" % (i+1, r)
