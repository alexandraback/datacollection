import sys

NUM_ROWS = 4

def read_row(infile):
    row_idx = int(infile.readline()) - 1

    for idx in range(NUM_ROWS):
        line = infile.readline()
        if idx == row_idx:
            row = map(int, line.split())
    
    return row

if __name__ == "__main__":

    testcases = int(sys.stdin.readline())

    for case in xrange(1, testcases+1):
        row1 = read_row(sys.stdin)
        row2 = read_row(sys.stdin)

        candidates = set(row1) & set(row2)

        if len(candidates) == 0:
            result = "Volunteer cheated!"
        elif len(candidates) == 1:
            result = str(candidates.pop())
        else:
            result = "Bad magician!"

        print("Case #{}: {}".format(case, result))
