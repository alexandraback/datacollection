#!/usr/bin/env python2

def case(T):
    nr = int(raw_input())
    parties = map(int, raw_input().split())

    evac = []
    while sum(parties) > 0:
        #print map(lambda x: 1.*x/sum(parties), parties)
        if any(filter(lambda x: x>0.5,map(lambda x: 1.*x/sum(parties), parties))): print "NOOOOO"
        m = max(parties)
        if parties.count(m) == 2:
            i1 = parties.index(m)
            i2 = parties.index(m, i1+1)
            evac.append(chr(65+i1) + chr(65+i2))
            parties[i1] -= 1
            parties[i2] -= 1
        else:
            i1 = parties.index(m)
            evac.append(chr(65+i1))
            parties[i1] -= 1
    return " ".join(evac)




if __name__=="__main__":
    for i in xrange(int(raw_input())):
        print "Case #{}: {}".format(i+1, case(i))
