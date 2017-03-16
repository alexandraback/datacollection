import sys
from sets import Set


def read_4_rows():
    rows = []
    for i in range(0, 4):
        rows.append(Set(map(int, sys.stdin.readline().split())))
    return rows

num_cases = int(sys.stdin.readline())
for case in range(1, num_cases + 1):
    row1 = int(sys.stdin.readline())
    board1 = read_4_rows()
    row2 = int(sys.stdin.readline())
    board2 = read_4_rows()
    result = board1[row1 - 1].intersection(board2[row2 - 1])
    response = ''
    if len(result) == 0:
        response = "Volunteer cheated!"
    elif len(result) > 1:
        response = "Bad magician!"
    else:
        response = str(result.pop())
    print("Case #" + str(case) + ": " + response)
