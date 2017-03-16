t = int(raw_input())
tt = 1
while tt <= t:
    n = int(raw_input())
    a = raw_input()
    b = raw_input()
    A, B, s = 0, 0, 0
    f = False
    while A < len(a) and B < len(b):
        if a[A] != b[B]:
            f = True
            break
        l = a[A]
        aa, bb = 0, 0
        while A < len(a) and a[A] == l:
            A += 1
            aa += 1
        while B < len(b) and b[B] == l:
            B += 1
            bb += 1
        s += abs(aa-bb)
        #print l,aa,bb,s
    if f or a[-1] != b[-1]:
        print "Case #{0}: Fegla Won".format(tt)
    else:
        print "Case #{0}: {1}".format(tt,s)
    tt += 1