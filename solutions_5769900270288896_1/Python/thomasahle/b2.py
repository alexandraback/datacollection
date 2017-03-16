import sys
read = lambda t=int: list(map(t,sys.stdin.readline().split()))
array = lambda *ds: [array(*ds[1:]) for _ in range(ds[0])] if ds else 0

def count(r, c, i):
    res = bin((i << c) & i).count('1')
    for j in range(r):
        row = i & (((1<<c)-1) << j*c)
        res += bin(row & (row << 1)).count('1')
    return res

# s = array(26,26,26)
# for r in range(1,26):
#     for c in range(1,r+1):
#         if r*c <= 25:
#             for k in range(26):
#                 s[r][c][k] = 10**9
#             for i in range(2**(r*c)):
#                 n = bin(i).count('1')
#                 s[r][c][n] = min(s[r][c][n], count(r,c,i))


def even(r, c):
    r, c = min(r,c), max(r,c)
    ss = [(r*c+1)//2,
        0,
        0,
        0,
        r*c]
    if r == 1:
        ss[1] = 0
        ss[2] = (c-1)//2
        if c % 2 == 0:
            ss[1] = 1
            ss[2] = (c-2)//2
    else:
        if (c%2,r%2) == (0,0):
            ss[2] = 2
            ss[3] = r-2 + c-2
        elif (c%2,r%2) == (1,1):
            ss[2] = 0
            ss[3] = r-1 + c-1
        else:
            ss[2] = 2
            ss[3] = r-1 + c-1 - 2
    return ss

def odd(r, c):
    r, c = min(r,c), max(r,c)
    ss = [(r*c)//2,
        0,
        0,
        0,
        r*c]
    if r == 1:
        ss[1] = 2
        ss[2] = (c-2)//2
        if c % 2 == 0:
            ss[1] = 1
            ss[2] = (c-2)//2
    else:
        if (c%2,r%2) == (0,0):
            ss[2] = 2
            ss[3] = r-2 + c-2
        elif (c%2,r%2) == (1,1):
            ss[2] = 4
            ss[3] = r-3 + c-3
        else:
            ss[2] = 2
            ss[3] = r-2 + c-2
    return ss

def solve_(ss, n):
    res = 0
    for i, s in enumerate(ss):
        res += i * min(s, n)
        n -= min(s, n)
    return res

def solve(r, c, n):
    return min(solve_(even(r,c),n), solve_(odd(r,c),n))

# if __name__ == '__main__':
#     s = array(20,20,20)
#     for r in range(1,17):
#         for c in range(1,r+1):
#             if r*c <= 16:
#                 for k in range(20):
#                     s[r][c][k] = 10**9
#                 for i in range(2**(r*c)):
#                     n = bin(i).count('1')
#                     s[r][c][n] = min(s[r][c][n], count(r,c,i))
                # if s[r][c][n] != solve(r,c,n):
                #     print('err', r, c, n)
                #     print(s[r][c][n], solve(r,c,n))


if __name__ == '__main__':
    T, = read()
    for t in range(T):
        R, C, N = read()
        print("Case #{}: {}".format(t+1, solve(R,C,N)))

