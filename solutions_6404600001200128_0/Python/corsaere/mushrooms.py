f = open('gcj1as')

cases = int(f.readline())
for case in range(cases):
    n_mush = int(f.readline())
    mush = [int(x) for x in f.readline().split()]
   
    m1 = 0
    m2 = 0
    max_diff = 0
    for x in range(len(mush)-1):
        #method1:
        if mush[x] > mush[x+1]:
            m1 = m1 + mush[x] - mush[x+1]
            if mush[x] - mush[x+1] > max_diff:
                max_diff = mush[x] - mush[x+1]
    m2 = max_diff * (len(mush)-1) 
    for x in range(len(mush)-1):
        if mush[x] < max_diff:
            m2 = m2 - (max_diff-mush[x])
    print "Case #"+ str(case+1) + ": " +str(m1) + " " + str(m2)
