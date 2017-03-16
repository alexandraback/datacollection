problem = 'A-small-attempt0'

fin = open(problem + '.in')
fout = open(problem + '.out', 'w')

def read_ints():
    return [int(x) for x in fin.readline().strip().split()]

T = read_ints()[0]
for caseno in range(1, T+1):
    ans1 = read_ints()[0]
    grid1 = [read_ints() for _ in range(4)]
    row1 = grid1[ans1-1]

    ans2 = read_ints()[0]
    grid2 = [read_ints() for _ in range(4)]
    row2 = grid2[ans2-1]
    
    possible_nums = set(row1).intersection(set(row2))
    if len(possible_nums) == 0:
        result = "Volunteer cheated!"
    elif len(possible_nums) > 1:
        result = "Bad magician!"
    else:
        result = str(next(iter(possible_nums)))
    
    fout.write(("Case #%d: " % caseno) + result + "\n")