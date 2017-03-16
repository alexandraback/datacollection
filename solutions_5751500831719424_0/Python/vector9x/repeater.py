def repeats(s,idx):
    k=0
    while idx+k<len(s) and s[idx]==s[idx+k]:
        k+=1
    return k

def equalize(reps):
    l, h = min(reps), max(reps)
    best = 1000000000
    for center in xrange(l,h+1):
        best = min(best, sum( abs(center-x) for x in reps))
    return best

for case in xrange(1,int(raw_input())+1):
    print "Case #%d:"%case,

    N = int(raw_input())
    words = [ raw_input() for i in xrange(N) ]

    idx = [0]*N
    points = 0
    answer = None
    while answer==None:
        lt = set( words[i][idx[i]] for i in xrange(N) )
        if len(lt)!=1: 
            answer = "Fegla Won"
            break
        
        reps = [ repeats(words[i], idx[i]) for i in xrange(N) ]
        m = min(reps)
        points += equalize(reps)
        #print "add ", reps,"minus", m
        for i in xrange(N):
            idx[i] += reps[i]
        
        ends = 0
        for i in xrange(N):
            assert idx[i]<=len(words[i])
            if idx[i]==len(words[i]): 
                ends+=1

        if ends>0:
            answer = points if ends==N else "Fegla Won"
    print answer
