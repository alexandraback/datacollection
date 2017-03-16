for T in xrange(input()):
    N = input()
    def collapse(s):
        s2 = [s[0]]
        c = [1]
        for i in xrange(1,len(s)):
            if s[i]==s2[-1]: c[-1]+=1
            else: s2.append(s[i]); c.append(1)
        return s2,c
    S = [collapse(raw_input().strip()) for _ in xrange(N)]
    if all(s==S[0][0] for s,c in S):
        x = 0
        n = len(S[0][0])
        for i in xrange(n):
            z = sorted(c[i] for _,c in S)[N/2]
            x+= sum(abs(c[i]-z) for _,c in S)
        print "Case #%d: %d"%(T+1,x)
    else:
        print "Case #%d: Fegla Won"%(T+1)
