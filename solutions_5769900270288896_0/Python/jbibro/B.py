__author__ = 'jakub.bibro'

def solve(R, C, N):
    max_walls = R * (C - 1) + C * (R - 1)
    # print max_walls
    to_remove = R * C - N
    D = [[1 for x in range(0, C)] for x in range(0, R)]
    # print D
    for i in range(0, to_remove):
        max_walls = max_walls - remove(D, R, C)

    return 0 if max_walls < 0 else max_walls

def remove(D, R, C):
    # print D
    a = -1
    b = -1
    max_value = -1
    curr_val = 0
    for i in range(0, R):
        for j in range(0, C):
            curr_val = 0
            #top
            if i > 0:
                if D[i-1][j] == 1 and D[i][j] == 1:
                    curr_val += 1
            #bottom
            if i < R - 1:
                if D[i + 1][j] == 1 and D[i][j] == 1:
                    curr_val += 1

            #left
            if j > 0:
                if D[i][j-1] == 1 and D[i][j] == 1:
                    curr_val += 1

            #right
            if j < C - 1:
                if D[i][j+1] == 1 and D[i][j] == 1:
                    curr_val += 1

            # print curr_val
            if curr_val > max_value:
                max_value = curr_val
                a = i
                b = j
    # print 'removing ', a, b
    # print 'removing ', max_value
    D[a][b] = 0
    return max_value




if __name__ == '__main__':
    test_cases = int(raw_input())
    for i in range(0, test_cases):
        R, C, N = [int(x) for x in raw_input().split(' ')]
        print('Case #{}: {}'.format(i + 1, solve(R, C, N)))