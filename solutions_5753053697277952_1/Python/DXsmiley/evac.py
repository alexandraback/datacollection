T = int(input())

for t in range(1, T + 1):
    N = int(input())
    K = list(map(int, input().split()))
    # K.sort(reverse = True)
    o = ''
    while sum(K) > 0:
        if sum([min(i, 1) for i in K]) > 2:
            L = K.index(max(K))
            K[L] -= 1
            o += chr(ord('A') + L) + ' '
        else:
            for i, v in enumerate(K):
                if v != 0:
                    o += chr(ord('A') + i)
                    K[i] -= 1
            o += ' '
    print("Case #{}: {}".format(t, o.strip()))
