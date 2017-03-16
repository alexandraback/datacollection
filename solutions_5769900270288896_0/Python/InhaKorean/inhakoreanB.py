f_test = ['test.in', 'test.out']
f_small = ['B-small-attempt0.in', 'small.out']
f_large = ['B-large.in', 'large.out']
f_practice_small = ['B-small-practice.in', 'practice_small.out']
f_practice_large = ['B-large-practice.in', 'practice_large.out']

#FILE_NAME = f_test
FILE_NAME = f_small
#FILE_NAME = f_large
#FILE_NAME = f_practice_small
#FILE_NAME = f_practice_large

f = open(FILE_NAME[0], 'r')
o = open(FILE_NAME[1], 'w')

def count(board, R, C) :
    ret = 0
    for i in range(R) :
        for j in range(C) :
            if board[i][j] == 1 and i+1 < R and board[i+1][j] == 1 : ret += 1
            if board[i][j] == 1 and j+1 < C and board[i][j+1] == 1 : ret += 1
    return ret

def solve(board, R, C, N, r, c, n) :
    if R == r :
        if N != n : return float("INF")
        return count(board, R, C)
    if C == c :
        return solve(board, R, C, N, r+1, 0, n)

    board[r][c] = 1
    ret = solve(board, R, C, N, r, c+1, n+1)
    board[r][c] = 0
    ret = min(ret, solve(board, R, C, N, r, c+1, n))

    return ret

def case_result(case) :
    R, C, N= map(int, f.readline().split())
    board = [ [0] * C for i in range(R)]
    return str(solve(board, R, C, N, 0, 0, 0))

T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
    
    
