import sys
f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    count = 0
    a = int(f.readline())
    A = []
    for i in range(4):
        A += [map(int, f.readline().split())]

    b = int(f.readline())
    B = []
    for i in range(4):
        B += [map(int, f.readline().split())]
    C = A[a-1]
    D = B[b-1]
    for i in range(4):
        for j in range(4):
            if C[i] == D[j]:
                store = C[i]
                count = count + 1
    if count == 1:
        print "Case #%d: %d" % (t+1,store)
    elif count > 1:
        print "Case #%d: Bad magician!" % (t+1)
    else:
        print "Case #%d: Volunteer cheated!" % (t+1)
    
