import sys
T = int(sys.stdin.readline())
for t in range(T):
    N = sys.stdin.readline()
    M = [int(m) for m in sys.stdin.readline().split()]


    diff_M = []
    for i in range(len(M) - 1):
        diff_M.append(M[i] - M[i+1])
    # sol 1
    ans1 = 0
    for diff in diff_M:
        if diff > 0:
            ans1 += diff
    # sol 2
    ans2 = 0
    

    max_speed = max(diff_M)
    if max_speed < 0: max_speed = 0
    #print 'max', max_speed
    ans2 = 0
    for i in range(len(M) - 1):
        if M[i] > max_speed:
            ans2 += max_speed
        else:
            ans2 += M[i]
        #print '*', ans2 



    print "Case #%d: %d %d" % (t+1, ans1, ans2)