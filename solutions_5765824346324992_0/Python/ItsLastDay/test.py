for test in range(1, int(input()) + 1):
    n, place = map(int, input().split())
    m = list(map(int, input().split()))

    free = [True for i in range(n)]
    until = [0 for i in range(n)]
    ans = 0
    cur = 1
    period = -1
    found = False
    for tm in range(max(m) * place + 1234):
        if found:
            break
        for i in range(n):
            if until[i] > 0:
                until[i] -= 1
                if until[i] == 0:
                    free[i] = True

        if all(free) and tm > 0:
            period = tm
            break

        for i in range(n):
            if free[i]:
                free[i] = False
                until[i] = m[i]
                if cur == place:
                    ans = i + 1
                    found = True   
                cur += 1

    if period != -1 and ans == 0:
        cur = (place - cur) // (cur - 1) * (cur - 1) + cur

        for tm in range(max(m) * place + 1234):
            if found:
                break
            for i in range(n):
                if until[i] > 0:
                    until[i] -= 1
                    if until[i] == 0:
                        free[i] = True
            if all(free) and tm > 0:
                period = tm
                break

            for i in range(n):
                if free[i]:
                    free[i] = False
                    until[i] = m[i]
                    if cur == place:
                        ans = i + 1
                        found = True   
                    cur += 1
    print('Case #%d: %d' % (test, ans))
