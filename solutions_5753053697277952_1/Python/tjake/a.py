from string import ascii_uppercase as name
for t in xrange(input()):
    print "Case #%d:"%(t+1),
    n = input()
    p = map(int, raw_input().split())
    gets = lambda:sorted(range(n), key=lambda x: p[x], reverse = True)

    ans = []
    su = sum(p)
    while su:
        ss = gets()
        s1 = ss[0]
        if p[s1] * 2 > su:
            exit(1)
        p[s1] -= 1
        ss = gets()
        s2 = ss[0]
        su -= 1
        if p[s2]*2 > su and p[s2] > 0:
            p[s2] -= 1
            ans.append(name[s1]+name[s2])
            su -= 1
        else:
            ans.append(name[s1])
    print " ".join(ans)
