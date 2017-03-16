def area(A,B,C):
    return (B[0]-A[0])*(B[1]+A[1])+(C[0]-B[0])*(C[1]+B[1])+(A[0]-C[0])*(A[1]+C[1])

T = int(input())
for case in range(1,T+1):
    print("Case #",case,": ",sep = '')
    N = int(input())
    trees = []
    left = [[0]*N for _ in range(N)]
    right = [[0]*N for _ in range(N)]
    for _ in range(N):
        x,y = (int(x) for x in input().split())
        trees.append((x,y))
    if N <= 3:
        for _ in range(N):
            print(0)
        continue
    best = [N]*N
    for (i,s) in enumerate(trees):
        for j in range(i+1,N):
            t = trees[j]
            for k in range(j+1,N):
                u = trees[k]
                test = area(s,t,u)
                if test>0:
                    left[i][j] += 1
                    left[j][k] += 1
                    left[k][i] += 1
                    right[j][i] += 1
                    right[k][j] += 1
                    right[i][k] += 1
                elif test<0:
                    right[i][j] += 1
                    right[j][k] += 1
                    right[k][i] += 1
                    left[j][i] += 1
                    left[k][j] += 1
                    left[i][k] += 1
    best = [N]*N
    for i in range(N):
        for j in range(N):
            if i==j:
                continue
            best[i] = min(best[i],left[i][j],right[i][j])
                

    for b in best:
        print(b)
