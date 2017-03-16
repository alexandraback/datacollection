tests = int(input())

let = lambda x : chr(ord('A') + x)
for t in range(1, tests+1):
    n = int(input())
    a = list(map(int, input().split()))
    b = sorted((a[i], i) for i in range(n))
    ans = []
    for j in range(b[-1][0] - b[-2][0]):
        ans.append(let(b[-1][1]))
    for i in range(n - 2):
        for j in range(b[i][0]):
            ans.append(let(b[i][1]))
    for j in range(b[-2][0]):
        ans.append(let(b[-1][1]) + let(b[-2][1]))
    print('Case #{}: {}'.format(t, ' '.join(ans)))
    
