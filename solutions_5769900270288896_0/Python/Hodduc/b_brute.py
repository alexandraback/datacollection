N = input()
for C in range(1, N+1):
    r, c, n = map(int, raw_input().split())

    if (r*c+1)/2 >= n:
        print "Case #%d:" % C, 0
        continue

    if r % 2 != 0:
        (r, c) = (c, r)

    answer = 9999999

    for MM in range(2**(r*c)):
        M = []
        cnt = 0

        for i in range(r):
            crow = []
            for j in range(c):
                if (MM & 2 ** (i * c + j)) != 0:
                    crow.append(1)
                    cnt += 1
                else:
                    crow.append(0)
            M.append(crow)

        if cnt != n:
            continue

        score = 0

        for i in range(r):
            for j in range(c):
                if M[i][j] == 0:
                    continue
                if i != 0 and M[i-1][j] == 1:
                    score += 1
                if j != 0 and M[i][j-1] == 1:
                    score += 1
        if score < answer:
            answer = score

    print "Case #%d:" % C, answer
