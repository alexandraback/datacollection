for i in range(1, int(input()) + 1):
    s = set([str(i) for i in range(1, 17)])
    for _ in range(2):
        N = int(input()) - 1
        M = [input().strip().split() for _ in range(4)]
        s = s & set(M[N])
    print('Case #{}: {}'.format(i, list(s)[0] if len(s) == 1 else 'Volunteer cheated!' if not s else 'Bad magician!'))
