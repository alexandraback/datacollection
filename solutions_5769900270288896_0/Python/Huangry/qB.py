__author__ = 'Tom'

import itertools

def calc (r, c, list):
    matrix = [[0 for i in range(c)] for j in range(r)] #matrix[r][c]
    unhappiness = 0
    for spot in list:
        matrix[int(spot/c)][int(spot%c)] = 1
    for i in range(r):
        for j in range(c-1):
            if matrix[i][j] ==1 and matrix[i][j+1] == 1:
                unhappiness +=1
    for i in range(r-1):
        for j in range(c):
            if matrix[i][j] ==1 and matrix[i+1][j] == 1:
                unhappiness +=1

    return unhappiness



with open ('B-small-attempt0 (3).in', 'r') as f:
    with open ('Bsolution.txt', 'w') as solution:

        T = int(f.readline())

        for case in range(T):
            line = f.readline().split()
            R, C, N = int(line[0]), int(line[1]), int(line[2])
            min = 4*N

            for i in itertools.combinations(range(R*C), N):
                result = calc(R, C, i)
                if result < min:
                    min = result


            solution.write('Case #' + str(case+1) + ': ' + str(min)+ '\n')
    solution.closed
f.closed
