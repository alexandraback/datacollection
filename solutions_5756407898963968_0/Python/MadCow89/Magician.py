import math

def solve(input_path, output_path):
    with open(input_path, 'r') as fin:
        with open(output_path, 'w') as fout: 
            num_cases = int(fin.readline())
            for i in xrange(num_cases):
                appearance = [False for j in xrange(16)]
                result = -1
                row_idx = int(fin.readline())
                for j in xrange(4):
                    row = fin.readline()
                    if j == row_idx - 1:
                        for number in row.strip().split(" "):
                            appearance[int(number)-1] = True
                row_idx = int(fin.readline())
                for j in xrange(4):
                    row = fin.readline()
                    if j == row_idx - 1:
                        for number in row.strip().split(" "):
                            if appearance[int(number)-1]:
                                if result < 0:
                                    result = int(number)
                                else:
                                    result = 17
                            else:
                                appearance[int(number)-1] = True
                if 0 < result < 17:
                    answer = str(result)
                elif result < 0:
                    answer = "Volunteer cheated!"
                else:
                    answer = "Bad magician!"
                fout.write("Case #" + str(i+1) + ": " + answer + "\n")

dir = "F:\\Sync\\Dropbox\\Coding\\CodeJam\\2014\\"
input_path = dir + "A-small-attempt0.in"
output_path = dir + "A-small.out"
solve(input_path, output_path)
