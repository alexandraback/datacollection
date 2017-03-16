
def solve(N,A):
    prev=None
    ans1 = 0
    maxi = 0
    for i in A:
        if prev==None: prev = i; continue
        else:
            change = prev-i
            if change > 0:
                ans1 += change
                maxi = max(change,maxi)
            prev = i
    #Now go back and review how many are eaten with maxi per second
    ans2 = 0
    for i in A[:-1]:
        ans2 += min(maxi,i)
    return str(ans1) + ' ' + str(ans2)


########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        N = rrI()
        A = rrM()
        zetaans = solve(N,A)
        zeta = "Case #%i: "%(tc+1) + str(zetaans)
        print zeta
        fo.write(zeta+'\n')
fo.close()
