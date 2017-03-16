import sys


def get_line():
    return sys.stdin.readline()

def get_case_prefix(idx):
    return "Case #" + str(idx+1) + ":"

def find_commons(first_row, second_row):
    return list(set(first_row) & set(second_row))

def process_testcase(idx):
    first_idx = int(get_line()) - 1
    first_grid = []
    for i in range(4):
        first_grid.append(get_line())

    second_idx = int(get_line()) - 1
    second_grid = []
    for i in range(4):
        second_grid.append(get_line())

    results = find_commons(first_grid[first_idx].strip().split(), second_grid[second_idx].strip().split())
    if len(results) == 0:
        print get_case_prefix(idx), "Volunteer cheated!"
    elif len(results) == 1:
        print get_case_prefix(idx), results[0]
    else:
        print get_case_prefix(idx), "Bad magician!"

def main():
    num_testcases = int(get_line())
    for idx in range(num_testcases):
        process_testcase(idx)

if __name__ == "__main__":
    main()
