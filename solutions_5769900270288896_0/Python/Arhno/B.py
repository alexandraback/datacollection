import numpy as np
import math

class Case:
    def __init__(self):
        self.R = None
        self.C = None
        self.N = None

    def get_score(self, grid):
        score = 0
        for i in range(self.R):
            for j in range(self.C):
                idx = j + i * self.C
                if grid[idx] == 1:
                    if i < self.R - 1:
                        idx = j + (i+1) * self.C
                        score += grid[idx]
                    if j < self.C - 1:
                        idx = (j+1) + i * self.C
                        score += grid[idx]
        return score

    def solve(self):
        nb_cells = self.R * self.C
        if self.N <= nb_cells / 2:
            return '0'
        else:
            best_score = np.Inf
            grid = [0 for k in range(nb_cells)]
            n = 0
            pos = 0
            while True:

                grid[pos] = 1
                n = sum(grid)
                score = self.get_score(grid)

                #print grid, n

                if n == self.N:
                    if score < best_score:
                        best_score = score

                    if sum(grid[nb_cells - self.N:]) == self.N:
                        return str(best_score)

                    grid[pos] = 0

                pos += 1
                if pos == nb_cells:
                    # we backtrack
                    pos -= 1
                    grid[pos] = 0
                    while grid[pos] == 0:
                        pos -= 1
                    grid[pos] = 0
                    pos += 1


def read_case(file):
    case = Case()
    line = file.readline().split(' ')
    values = map(int, line)
    case.R = values[0]
    case.C = values[1]
    case.N = values[2]
    return case


def main():
    filename_in = 'B-small-attempt0.in'
    filename_out = 'B-small-attempt0.out'
    file_in = open(filename_in)
    file_out = open(filename_out, 'w')

    nb_case = int(file_in.readline())

    for k in range(1, nb_case + 1):
        case = read_case(file_in)
        to_write = 'Case #' + str(k) + ': ' + case.solve()
        print to_write
        file_out.write(to_write + '\n')

    file_out.close()


if __name__ == '__main__':
    main()