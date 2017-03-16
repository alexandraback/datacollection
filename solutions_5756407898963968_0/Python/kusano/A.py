for t in range(input()):
    r1 = input()
    s1 = set([map(int, raw_input().split()) for _ in range(4)][r1-1])
    r2 = input()
    s2 = set([map(int, raw_input().split()) for _ in range(4)][r2-1])
    s = s1&s2
    if len(s)==0:
        a = "Volunteer cheated!"
    elif len(s)==1:
        a = s.pop()
    else:
        a = "Bad magician!"
    print "Case #%s: %s" % (t+1, a)
