from itertools import combinations

def solve(R, C, N):
    """ solve the problem """

    #print(R, C, N)
    ans = 9999999
    cs = combinations([i for i in range(R*C)], N)
    for c in cs: 
        count = 0
        A = [[0 for x in range(C) ] for y in range(R)]
        for i in c:
            ii = int(i/C)
            jj = i%C
            A[ii][jj] = 1
        for i in range(R):
            for j in range(C):
                if A[i][j] == 0: continue
                if i+1 < R:
                    if A[i+1][j] == 1: count += 1
                if j+1 < C:
                    if A[i][j+1] == 1: count += 1
        ans = min(ans, count)

    return ans


def parse():
    """ parse input """
    R, C, N = [int(i) for i in input().split()]

    return R, C, N


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
