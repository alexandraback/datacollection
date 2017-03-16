#!/usr/bin/python
import sys, collections

data = file(sys.argv[1]).read().splitlines()

T = int(data.pop(0))

def convert(s):
    ch = s[0]
    l = 1
    out = []
    for i in xrange(1,len(s)):
        if ch == s[i]:
            l = l + 1
            continue
        else:
            out.append( (ch, l) )
            ch = s[i]
            l = 1
    out.append( (ch, l) )
    return out
        
def brute2(N, STR):
    VAL = []
    for i in xrange(0,N):
        VAL.append(convert(STR[i]))
        
    len1 = len(STR[0])
    len2 = len(STR[1])
    ans = abs(len1-len2)
#    print abs(len1-len2)
#    print
#    for i in xrange(0,N):
#        print STR[i]
#        print VAL[i]

    # make sure all same len
    l = len(VAL[0])
    for i in xrange(0,N):
        if len(VAL[i]) != l:
            return -1

    totaldiff = 0
    for i in xrange(0,l):
        # make sure all same char
        (ch, tl) = VAL[0][i]
        mmax = 0
        for j in xrange(0,N):
            (xch, xtl) = VAL[j][i]
            if xch != ch:
                return -1
            mmax = max(mmax, xtl)
          
    larray = []
    minlen = 10000
    maxlen = 0
    for j in xrange(0,N):
        larray.append(len(STR[j]))
        minlen = min(minlen,len(STR[j]))
        maxlen = max(maxlen,len(STR[j]))
    
    print 'min:max',minlen,maxlen+1
    mdiff = 101*N
    for target in xrange(minlen,maxlen+2):
        curdiff = 0
        print 'target',target
        for j in xrange(0,N):
            print STR[j], abs(target-larray[j])
            curdiff = curdiff + abs(target-larray[j])
        mdiff = min(mdiff,curdiff)

#    print ans, mdiff
#    assert ans == mdiff
    return mdiff

def brute(N, STR):
    VAL = []
    for i in xrange(0,N):
        VAL.append(convert(STR[i]))
        
    if False:
        len1 = len(STR[0])
        len2 = len(STR[1])
        ans = abs(len1-len2)
#        print abs(len1-len2)
        print
        for i in xrange(0,N):
            print STR[i]
            print VAL[i]

    # make sure all same len
    l = len(VAL[0])
    for i in xrange(0,N):
        if len(VAL[i]) != l:
            return -1

    totaldiff = 0
    for i in xrange(0,l):
        # make sure all same char
        (ch, tl) = VAL[0][i]
        mmax = 0
        for j in xrange(0,N):
            (xch, xtl) = VAL[j][i]
            if xch != ch:
                return -1
            mmax = max(mmax, xtl)
            
        (ach, atl) = VAL[0][i]
        (bch, btl) = VAL[1][i]

        adiff = abs(atl-btl)

        # find min diff
        mdiff = (101)*N
        for target in xrange(1,mmax+2):
            curdiff = 0
            for j in xrange(0,N):
                (xch, xtl) = VAL[j][i]
                curdiff = curdiff + abs(xtl-target)
            mdiff = min(mdiff,curdiff)
            
#        assert(mdiff != (mmax+1)*N)
#        print 'mdiff',totaldiff,mdiff,l,ch
#        assert mdiff ==adiff
        assert mdiff >= 0
        totaldiff = totaldiff + mdiff
        
        
#    print 'ans',ans,totaldiff
#    assert ans == totaldiff
    return totaldiff

                        

for numcase in xrange(1,T+1):
    print 'Case #%d:' % numcase,
    N = int(data.pop(0))
    STR = []
    for i in xrange(0,N):
        STR.append(data.pop(0))

    v = brute(N, STR)
    if v == -1:
        print 'Fegla Won'
    else:
        print v


    

    

