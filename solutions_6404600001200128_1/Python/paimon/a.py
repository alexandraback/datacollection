t = int(input())
output = 'Case #{}: {} {}'
for i in range(t):
    n = int(input())
    l = [int(x) for x in input().split()]
    c1 = sum(max(x - y, 0) for x, y in zip(l, l[1:]))
    r = max(max(x - y, 0) for x, y in zip(l, l[1:]))
    c2 = sum(min(r, x) for x in l[:-1])
    print(output.format(i + 1, c1, c2))
