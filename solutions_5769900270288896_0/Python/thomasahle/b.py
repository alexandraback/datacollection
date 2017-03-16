import sys
read = lambda t=int: list(map(t,sys.stdin.readline().split()))
array = lambda *ds: [array(*ds[1:]) for _ in range(ds[0])] if ds else 0

def count(r, c, i):
    res = bin((i << c) & i).count('1')
    for j in range(r):
        row = i & (((1<<c)-1) << j*c)
        res += bin(row & (row << 1)).count('1')
    return res

s = array(20,20,20)
for r in range(1,17):
    for c in range(1,r+1):
        if r*c <= 16:
            for k in range(20):
                s[r][c][k] = 10**9
            for i in range(2**(r*c)):
                n = bin(i).count('1')
                s[r][c][n] = min(s[r][c][n], count(r,c,i))

# print(s)

# print(count(3,3,int('000000000',2)))

T, = read()
for t in range(T):
    R, C, N = read()
    R, C = max(R, C), min(R, C)
    print("Case #{}: {}".format(t+1, s[R][C][N]))

