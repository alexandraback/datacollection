for c in range(int(input())):
    R, C, N = list(map(int, input().split()))
    n = N
    t = R * C
    if t % 2 == 0:
        f = t // 2
    else:
        f = (t // 2) + 1
    if N <= f:
        print("Case #{}: {}".format(c+1, 0))
    else:
        N -= f
        if R == 1 or C == 1:
            if t % 2 == 0:
                f_C = 1
            else:
                f_C = 0
        elif t % 2 == 0:
            f_C = 2            
        else:
            f_C = 0
        
        f_E = 0
        if C % 2 == 0:
            for i in range(1, R-1):
                f_E += 1
        else:
            for i in range(1, R-1):
                if i % 2 != 0:
                    f_E += 2
        if R != 1 and C != 1:
            f_E += (C // 2) * 2
        else:
            f_E += (C // 2)
        if R % 2 != 0 or C % 2 != 0:
            f_E += 1
        f_E -= f_C
        
        #print()
        #print(t, N, f_C, f_E)
        counter = 0
        if n >= 8:
            counter -= 1
        if C != 1 and R != 1:
            while N > 0:
                if f_C > 0:
                    f_C -= 1
                    counter += 2
                elif f_E > 0:
                    f_E -= 1
                    counter += 3
                else:
                    counter += 4
                N -= 1
        else:
            counter = (N*2) - 1
            
        print("Case #{}: {}".format(c+1, counter))