cases = int(input())
for case in range(cases):
    n = int(input())
    m = list(map(int, input().split()))
    diffs = [m[i+1] - m[i] for i in range(n - 1)]
    rate = -min(diffs)
    sum1 = -sum(d for d in diffs if d < 0)
    sum2 = sum(min(mi, rate) for mi in m[:-1])
    print("Case #{}: {} {}".format(case+1, sum1, sum2))
