import sys

# INPUT DATA AND NUMBER OF TEST CASES
infile = open(sys.argv[1],'r')
T = infile.readline()
T = T.rstrip()

# ITERATE OVER EACH CASE
for index in range(1,int(T)+1):
    N = int(infile.readline().rstrip())
    P = infile.readline().rstrip().split(' ');

    for i in range(N):
        P[i] = int(P[i])
    evacs = []
    
    while max(P) > 1:
        
        major = ''
        minor = ''
        if P[0]>P[1]:
            m, m2 = P[0], P[1]
            major, minor = chr(65), chr(66)
        else:
            m, m2 = P[1], P[0]
            major, minor = chr(66), chr(65)

        idx = 1
        for x in P[2:]:
            idx = idx + 1
            if x>m2:
                if x>m:
                    m2,m = m,x
                    major, minor = chr(65 + idx), major
                else:
                    m2 = x
                    minor = chr(65 + idx)
                    
        if m - m2 > 1:
            evacs.append(major + major)
            P[ord(major) - 65] = P[ord(major) - 65] - 2
        else:
            evacs.append(major + minor)
            P[ord(major) - 65] = P[ord(major) - 65] - 1
            P[ord(minor) - 65] = P[ord(minor) - 65] - 1

    if sum(P) % 2 == 1:
        balanced = 0
        for i in range(len(P)):
            if balanced == 0 and P[i] > 0:
                balanced = 1
                P[i] = 0
                evacs.append(chr(65 + i))

    s = ['', '']
    balance = 0
    for i in range(len(P)):
        if P[i] > 0:
            s[balance] = chr(65 + i)
            balance = balance + 1

        if balance == 2:
            evacs.append(s[0] + s[1])
            balance = 0
            
    # OUTPUT IN THE FORM
    print 'Case #' + str(index) + ': ',
    for item in evacs:
        print item,
    print '\n',
