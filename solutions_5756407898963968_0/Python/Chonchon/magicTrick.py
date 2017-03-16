import collections

f = open("/Users/vchoubard/Downloads/A-small-attempt0.in", "r")
output = open("/Users/vchoubard/Downloads/output.txt", "w")

T = int(f.readline())


def getRow():
    row_answer = {}
    num_of_row = 4
    row_num_answer = int(f.readline())
    for row in range(num_of_row):
        current_row = map(int, f.readline().split(" "))
        if row+1 == row_num_answer:
            row_answer = current_row
    return row_answer

for testcase in range(T):
    first_row = getRow()
    second_row = getRow()
    total_raw = first_row + second_row
    y = collections.Counter(total_raw)
    list_double = [i for i in y if y[i] > 1]
    length = len(list_double)
    if length == 0:
        output.write("Case #" + str(testcase+1) + ": Volunteer cheated!\n")
    elif length == 1:
        output.write("Case #" + str(testcase+1) + ": " + str(list_double.pop()) + "\n")
    else:
        output.write("Case #" + str(testcase+1) + ": Bad magician!\n")

f.close()
output.close()
