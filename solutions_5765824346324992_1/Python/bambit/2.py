r = open('2.test')
T = int(r.readline().rstrip())
for tcase in range(1, T+1):
    B, N = map(int, r.readline().rstrip().split())
    M = map(int, r.readline().rstrip().split())

    if N <= B:
        answer = N

    else:
        # Binary search for t
        mn = 1
        mx = min(M)*N
        t = (mn + mx) // 2
        while True:

            people_before_me = 0
            people_next_turn = 0
            for i in range(1, B+1):
                people_before_me += (t-1)//M[i-1] + 1 
                people_next_turn += t//M[i-1] + 1


            if people_before_me <= N-1 and people_next_turn >= N:
                break
            elif people_next_turn < N:
                mn = t+1
                mx = mx
                t = (mn + mx)//2
            else:
                mn = mn
                mx = t-1
                t = (mn + mx)//2

    pos_in_line = N-people_before_me
    custs = 0

    for i in range(1, B+1):
        if t % M[i-1] == 0:
            custs += 1
            if custs == pos_in_line:
                answer = i
                break

    print 'Case #%d: %s' % (tcase, answer)
r.close()
