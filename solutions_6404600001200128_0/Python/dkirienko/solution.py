def solve():
    n = int(input())
    A = list(map(int, input().split()))
    ans1 = 0
    for i in range(1, len(A)):
        if A[i] < A[i - 1]:
            ans1 += A[i - 1] - A[i]
    ans2 = 0
    m = 0
    for i in range(1, len(A)):
        if A[i] < A[i - 1]:
            m = max(m, A[i - 1] - A[i])
    for i in range(1, len(A)):
        if A[i - 1] > m:
            ans2 += m
        else:
            ans2 += A[i - 1]
    return str(ans1) + " " + str(ans2)

for i in range(1, int(input()) + 1):
    print("Case #", i, ": ", solve(), sep="")

