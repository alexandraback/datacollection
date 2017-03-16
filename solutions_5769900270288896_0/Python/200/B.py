import os
import sys

problem_id = 'B'

sys.setrecursionlimit(10**9)
input_path = '%s.in' % problem_id
output_path = '%s.out' % problem_id


def read_line():
    line = ''
    while len(line) == 0:
        line = input_file.readline().strip()
    return line


def write_line(line):
    print line
    return output_file.write(line + os.linesep)


def search(grid, index, n):
    if n > 0:
        return search()




def solve():
    r, c, n = map(int, read_line().split(' '))
    if n < 2:
        return 0
    count = r * c
    min_cost = 99999999
    test = '{0:0' + str(count) + 'b}'
    for i in xrange(2 ** count):
        grid = test.format(i)
        if count - len(grid.replace('1', '')) == n:
            rooms = [grid[j*c:(j+1)*c] for j in xrange(r)]
            cost = 0
            for j in xrange(r - 1):
                for k in xrange(c):
                    if rooms[j][k] == rooms[j + 1][k] == '1':
                        cost += 1
            for j in xrange(c - 1):
                for k in xrange(r):
                    if rooms[k][j] == rooms[k][j + 1] == '1':
                        cost += 1
            if cost < min_cost:
                min_cost = cost
    return min_cost


input_file = open(input_path, "r")
output_file = open(output_path, "w+")
T = int(read_line())
for case_id in xrange(1, T + 1):
    write_line("Case #%d: %s" % (case_id, solve()))
input_file.close()
output_file.close()