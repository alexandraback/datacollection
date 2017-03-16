import sys

# sys.stdin = open('b.in', 'r')
# sys.stdin = open('B-small-attempt1.in', 'r')
# sys.stdout = open('B-small-attempt1.out', 'w')
sys.stdin = open('B-large.in', 'r')
sys.stdout = open('B-large.out', 'w')


def solve(k0, k1, k2, k3, N):
    # print(k0, k2, k3, N)
    ans = 0
    N = max(N - k0, 0)
    ans += 1 * min(N, k1)
    N -= min(N, k1)
    ans += 2 * min(N, k2)
    N -= min(N, k2)
    ans += 3 * min(N, k3)
    N -= min(N, k3)
    ans += 4 * N
    # print(ans)
    return ans


def f(R, C, N):

    result = (R-1)*C + R*(C-1)

    for M in range(1 << R*C):
        cnt = sum([1 if c == '1' else 0 for c in bin(M)[2:]])
        if cnt != N:
            continue
        ans = 0
        for i in range(R):
            for j in range(C):
                if M & (1 << (i*C+j)):
                    if j > 0 and M & (1 << i*C+j-1):
                        ans += 1
                    if i > 0 and M & (1 << (i-1)*C+j):
                        ans += 1
        result = min(result, ans)

    return result


def cc(n):
    ans = 0
    while n:
        ans += n % 1
        n >>= 1


for t in range(int(input())):

    R, C, N = map(int, input().split())

    result = (R-1)*C + R*(C-1)

    if R == 1 or C == 1:

        # 按奇数序分

        k0 = (R * C + 1) // 2
        k1 = 0 if R * C % 2 else 1
        k2 = R + C - 1 - k0 - k1
        k3 = 0

        result = min(result, solve(k0, k1, k2, k3, N))

        # 按偶数序分

        k0 = (R * C) // 2
        k1 = 2 if R * C % 2 else 1
        k2 = R + C - 1 - k0 - k1
        k3 = 0

        result = min(result, solve(k0, k1, k2, k3, N))

    else:

        k1 = 0

        # 按奇数序分

        k0 = (R * C + 1) // 2
        k2 = 0 if R * C % 2 else 2
        k3 = R + C - 2 - k2

        result = min(result, solve(k0, k1, k2, k3, N))

        # 按偶数序分

        k0 = (R * C) // 2
        k2 = 4 if R * C % 2 else 2
        k3 = R + C - 2 - k2

        result = min(result, solve(k0, k1, k2, k3, N))

    # if result != f(R, C, N):
    #     print(R, C, N)
    print('Case #%d: %d' % (t + 1, result))
        # print('Case #%d: %d' % (t + 1, f(R,C,N)))

sys.stdin.close()
sys.stdout.close()