T = int(raw_input())
for test_index in xrange(T):
    B, N = map(int, raw_input().split())
    M = map(int, raw_input().split())

    def calc(t):
        n = 0
        for i in xrange(B):
            n += (t + M[i] - 1) / M[i]
        return n

    left, right = 0, min(M) * N
    left_val, right_val = calc(left), calc(right)
    while True:
        # left_val < N <= right_val
        middle = (left + right) / 2
        middle_val = calc(middle)
        if middle_val < N:
            left = middle
            left_val = middle_val
        else:
            right = middle
            right_val = middle_val

        if right <= left + 1:
            break

    answer = None
    n = left_val
    for i in xrange(B):
        if left % M[i] == 0:
            n += 1
            if n == N:
                answer = i + 1
                break

    print 'Case #{}: {}'.format(test_index + 1, answer)
