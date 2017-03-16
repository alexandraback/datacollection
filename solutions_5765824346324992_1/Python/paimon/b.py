def f(t, m):
    return sum(t//x for x in m) + len(m)

# min(t: f(t) >= n)
def f_inv(n, m, begin=None, end=None):
    if begin is None: begin = 0
    if end is None: end = 100000*n
    if begin == end:
        return begin
    t = (begin + end)//2;
    v = f(t, m)
    if v < n:
        return f_inv(n, m, t + 1, end)
    return f_inv(n, m, begin, t)

def solve(n, m):
    t = f_inv(n, m)
    v = f(t, m)
    for i, mi in enumerate(reversed(m)):
        if t%mi == 0:
            if v == n:
                return len(m) - i
            v -= 1

t = int(input())
output = 'Case #{}: {}'
for i in range(t):
    b, n = map(int, input().split())
    m = [int(x) for x in input().split()]
    print(output.format(i + 1, solve(n, m)))

