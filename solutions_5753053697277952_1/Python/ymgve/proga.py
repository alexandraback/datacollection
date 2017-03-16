import sys

import psyco; psyco.full()

def consistent(parties):
    largest = 0
    total = 0
    for p, n in parties:
        largest = max(largest, p)
        total += p
        
    if largest * 2 > total:
        raise Exception("INCONSISTENT")
        
    return total
    
def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        nparties = int(f.readline().strip())
        parties = []
        pname = ord("A")
        for p in f.readline().strip().split():
            parties.append([int(p), chr(pname)])
            pname += 1
            
        parties.sort()
        
        plan = []
        
        #evacuate largest party until the size of second largest
        while (parties[-1][0] - 2) >= parties[-2][0] and parties[-1][0] >= 2:
            plan.append(parties[-1][1] * 2)
            parties[-1][0] -= 2
            consistent(parties)
            
        # evacuate any potential last straggler in largest party
        if (parties[-1][0] - 1) == parties[-2][0] and parties[-1][0] >= 1:
            plan.append(parties[-1][1])
            parties[-1][0] -= 1
            consistent(parties)
            
        # evacuate other parties
        for i in xrange(len(parties)-2):
            for j in xrange(parties[i][0]):
                plan.append(parties[i][1])
                parties[i][0] -= 1
            consistent(parties)
            
        # evacuate last two parties in tandem
        for i in xrange(parties[-1][0]):
            plan.append((parties[-2][1] + parties[-1][1]))
            parties[-2][0] -= 1
            parties[-1][0] -= 1
            consistent(parties)
            
        total = consistent(parties)
        if total != 0:
            raise Exception("NOT EVERYONE OUT")
            
        print "Case #%d: %s" % (caseno+1, " ".join(plan))
        
main()