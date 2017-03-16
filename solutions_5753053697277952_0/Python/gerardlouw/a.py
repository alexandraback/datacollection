T = int(input())
for t in range(1, T + 1):
    print("Case #%d:" % t, end=" ")
    N = int(input())
    A = [int(x) for x in input().split()]
    if N == 2:
        for _ in range(A[0]):
            print("AB", end=" ")
    else:
        while True:
            i = max(range(len(A)), key=A.__getitem__)
            if A[i] == 0: break
            if A[i] == 1 and sum(A) == 2:
                j = max(range(i+1, len(A)), key=A.__getitem__)
                print(chr(65 + i) + chr(65 + j), end=" ")
                break
            else:
                print(chr(65 + i), end=" ")
                A[i] -= 1
    print()
