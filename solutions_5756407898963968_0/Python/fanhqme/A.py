T=int(raw_input())

for case in xrange(1,T+1):
    r1=int(raw_input())-1
    A=[map(int,raw_input().strip().split()) for i in xrange(4)]
    r2=int(raw_input())-1
    B=[map(int,raw_input().strip().split()) for i in xrange(4)]
    intersect=[i for i in A[r1] if i in B[r2]]
    print 'Case #%d:'%case,
    if len(intersect)==0:
        print 'Volunteer cheated!'
    elif len(intersect)>1:
        print 'Bad magician!'
    else:
        print intersect[0]
