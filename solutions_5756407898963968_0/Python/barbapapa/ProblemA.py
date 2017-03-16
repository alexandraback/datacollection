__author__ = 'barbapapa'


def read_input(f_name):
    cases = []
    with open(f_name) as f:
        nr_cases = int(f.readline().strip())
        for c in range(nr_cases):
            row_nr1 = int(f.readline().strip())
            grid1 = []
            for i in range(4):
                grid_row1 = [int(x) for x in f.readline().strip().split(' ')]
                grid1.append(grid_row1)
            row_nr2 = int(f.readline().strip())
            grid2 = []
            for i in range(4):
                grid_row2 = [int(x) for x in f.readline().strip().split(' ')]
                grid2.append(grid_row2)
            cases.append((row_nr1, row_nr2, grid1, grid2))
    return cases


def write_output(f_name, results):
    with open(f_name, 'w') as f:
        for i, r in enumerate(results):
            f.write('Case #'+str(i+1)+': '+r+'\n')


def solve_case(data):
    row_nr1, row_nr2, grid1, grid2 = data
    chosen_row1 = set(grid1[row_nr1-1])
    chosen_row2 = set(grid2[row_nr2-1])
    intersect = chosen_row1.intersection(chosen_row2)
    if len(intersect) == 1:
        return str(intersect.pop())
    elif len(intersect) == 0:
        return 'Volunteer cheated!'
    else: #len > 1
        return 'Bad magician!'


file_name = 'A-small-attempt0'
cases = read_input(file_name+'.in')
solution = [solve_case(x) for x in cases]
write_output(file_name+'.out', solution)
