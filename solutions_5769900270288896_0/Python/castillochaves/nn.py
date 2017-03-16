def read(f):
    return (int(s) for s in f.readline().split())

def calc(data):
    R, C, N = data
    S = R * C
    H = S / 2 + S % 2
    if N <= H:
        return 0
    W = (C - 1) * R + C * (R - 1)
    if N == S:
        return W
    if R == 1 or C == 1:
        L = max(R, C)
        W = 0 if S % 2 != 0 else 1
        X = L / 2 - W
    else:
        W = 0
        L = R + R + (C - 2) + (C - 2)
        X = 2 if S % 2 == 0 else 0
    Y = L / 2 - X
    Z = S - H - X - Y
    u = 0
    while (N > H):
        #print X, Y, Z
        N -= 1
        if W > 0:
            u += 1
            W -= 1
        elif X > 0:
            u += 2
            X -= 1
        elif Y > 0:
            if Y > 2:
                u += 3
                Y -= 1
            elif S % 2 == 0:
                u += 3
                Y -= 1
            else:
                u += 2 if Y == 2 else 4
                Y -= 1
        else:
            u += 4
            Z -= 1
    return u

def write(solution):
    return str(solution)

def solve(f):
    data = read(f)
    solution = calc(data)
    return write(solution)

if __name__ == '__main__':
    import sys
    with open(sys.argv[1]) as f:
        T = int(f.readline())
        for t in range(1, T+1):
            print('Case #{t}: {solution}'.format(t=t, solution=solve(f)))
