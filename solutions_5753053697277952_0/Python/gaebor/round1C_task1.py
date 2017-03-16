import sys
import numpy

test_cases = int(sys.stdin.readline().strip())

for t in range(1, test_cases + 1):
    num_parties = int(sys.stdin.readline().strip())
    party_members = numpy.array(sys.stdin.readline().strip().split(), dtype=int)
    print "Case #%d:" % t, 
    while party_members.sum() > 0:
        e = party_members.max()
        e1 = party_members.argmax()
        if (party_members == e).sum() == 2:
            party_members[e1] -= 1
            e2 = party_members.argmax()
            party_members[e2] -= 1
            print chr(e1 + ord("A"))+chr(e2 + ord("A")),
        else:
            print chr(e1 + ord("A")),
            party_members[e1] -= 1        
    print 