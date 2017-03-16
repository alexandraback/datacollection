#!/usr/bin/env python3
T = int(input())

for t in range(T):
    R, C, N = map(int, input().split())

    oN = N
    total = R*C

    X = total - R*C//2

    if C == 1:
        R, C = C, R

    if R == 1:
        cost = 0
        if C % 2 == 0:
            N -= C // 2
            if N <= 0:
                pass
            else:
                N -= 1
                cost += 1
                cost += 2 * N
        else:
            N -= C // 2 + 1
            if N <= 0:
                pass
            else:
                cost += 2 * N
        print('Case #{}: {}'.format(t+1, cost))
        continue



    if R % 2 == 0 or C % 2 == 0:
        circle = 2
        triangle = R + C - 4
    else:
        circle = 0
        triangle = R + C - 2

    square = (R-2)*(C-2)//2

    cost = 0
    N -= X
    if N < 0:
        pass
    else:
        N -= circle
        cost += 2 * circle
        if N < 0:
            cost += N * 2
        else:
            N -= triangle
            cost += 3 * triangle
            if N < 0:
                cost += N * 3
            else:
                N -= square
                cost += 4 * square
                if N < 0:
                    cost += N * 4

    min_cost = cost

    N = oN
    # Check second way for both odd:
    if not (R % 2 == 0 or C % 2 == 0):
        X = total//2
        circle = 4
        square = (R-2)*(C-2) - (R-2)*(C-2)//2
        triangle = total - X - circle - square
        cost = 0
        N -= X
        if N < 0:
            pass
        else:
            N -= circle
            cost += 2 * circle
            if N < 0:
                cost += N * 2
            else:
                N -= triangle
                cost += 3 * triangle
                if N < 0:
                    cost += N * 3
                else:
                    N -= square
                    cost += 4 * square
                    if N < 0:
                        cost += N * 4

        min_cost = min(min_cost, cost)

    print('Case #{}: {}'.format(t+1, min_cost))
    
