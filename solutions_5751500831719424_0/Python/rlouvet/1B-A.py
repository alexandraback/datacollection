T = int(raw_input())

for t in xrange(T):
    print "Case #%d:" % (t + 1),

    N = int(raw_input())

    table = [[] for i in xrange(N)]

    for w in xrange(N):
        word = list(raw_input())
        print word ##delete !
        for i in xrange(len(word)):
            print i  ##delete !
            lcount = 0
            if (i==0):
                table[w] = [word[0],1]
                lcount = lcount+1
            elif (word[i]==word[i-1]):
                print table[w][lcount][0]
                print table[w][lcount][1]
                table[w][lcount] = [table[w][lcount][0],table[w][lcount][1]+1]
            print table[w]