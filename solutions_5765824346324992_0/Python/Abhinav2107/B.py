T = int(raw_input())
for _case_ in xrange(T):
    B, N = [int(_) for _ in raw_input().split()]
    M = [int(_) for _ in raw_input().split()]
    min_time = -1
    max_time = 0
    min_started = 0
    while True:
        started = 0
        for m in M:
            started += (max_time // m) + 1
        if started >= N:
            break;
        min_time = max_time
        min_started = started
        if max_time == 0:
            max_time += 1
        else:
            max_time *= 2
    while max_time - min_time > 1:
        time = (min_time + max_time) // 2
        started = 0
        for m in M:
            started += (time // m) + 1
        if started >= N:
            max_time = time
        else:
            min_started = started
            min_time = time
    for i in xrange(B):
        if (min_time % M[i]) == (M[i] - 1):
            min_started += 1
        if min_started == N:
            print "Case #"+str(_case_+1)+": "+str(i+1)
            break
