import sys

cases = int(sys.stdin.readline().strip())

for case in range(1, cases + 1):
    row1 = int(sys.stdin.readline().strip())
    for row in range(1, 4 + 1):
        rowNumbers = sys.stdin.readline()
        if row == row1:
            chosenRow = rowNumbers
    chosenRow1 = map(int, chosenRow.split())

    row2 = int(sys.stdin.readline().strip())
    for row in range(1, 4 + 1):
        rowNumbers = sys.stdin.readline()
        if row == row2:
            chosenRow = rowNumbers
    chosenRow2 = map(int, chosenRow.split())

    common = set(chosenRow1) & set(chosenRow2)
    if len(common) == 0:
        result = "Volunteer cheated!"
    elif len(common) == 1:
        result = common.pop()
    else:
        result = "Bad magician!"

    print("Case #{}: {}".format(case, result))


