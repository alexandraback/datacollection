#infile = "A-large.in"
infile = "A_test.txt"
outfile = "A-large.out"

#lines = """""".split("\n")

lines = [l.strip() for l in open(infile,"r")]
from collections import defaultdict, Counter
from functools import partial

num_cases = int(lines[0])
lines = lines[1:]

cases = [None for i in range(num_cases)]

def make_grid(four_lines):
    return [[int(i) for i in row.split()]
            for row in four_lines]

for i in range(num_cases):
    q1 = int(lines[0]) - 1
    grid1 = make_grid(lines[1:5])
    q2 = int(lines[5]) - 1
    grid2 = make_grid(lines[6:10])
    lines = lines[10:]
    cases[i] = (q1, grid1, q2, grid2)

def process_case(case):
    q1, grid1, q2, grid2 = case
    possibilities = [i for i in grid1[q1] if i in grid2[q2]]
    num_poss = len(possibilities)
    if num_poss == 0:
        return "Volunteer cheated!"
    elif num_poss > 1:
        return "Bad magician!"
    else:
        return str(possibilities[0])
    

with open(outfile,"w") as g:
    
    for i, case in enumerate(cases):
        g.write("Case #" + str(i + 1) + ": " + process_case(case) + "\n")
    

