# IO file paths
file_in = "A-small-attempt1.in"
file_out = "A-small-attempt1.out"

# Board dimensions
N = 4
M = 4

# Solves the problem
def Solve(r1, b1, r2, b2):
    # Possible results when the trick fails
    amb = "Bad magician!"
    cheat = "Volunteer cheated!"

    # Cards in the row chosen first and second time
    candidates1 = b1[r1 - 1]
    candidates2 = b2[r2 - 1]
    # Cards that match the criteria
    candidates = []
    for c in candidates1:
        if c in candidates2:
            candidates.append(c)
    
    # Do the magic
    if 0 == len(candidates):
        return cheat
    if 1 == len(candidates):
        return candidates[0]
    return amb
    
# Reads the input data and runs the test cases
def Run():
    fin = open(file_in, 'r')
    fout = open(file_out, 'w')

    lines = []
    for l in fin:
        lines.append(l)

    i = 0
    T = int(lines[0])
    i = i + 1
    for t in range(0, T):
        r1 = int(lines[i])
        b1 = []
        i = i + 1
        for j in range(0, N):
            b1.append(lines[i].rstrip().split(' '))
            i = i + 1
        r2 = int(lines[i])
        b2 = []
        i = i + 1
        for j in range(0, N):
            b2.append(lines[i].rstrip().split(' '))
            i = i + 1
        result = Solve(r1, b1, r2, b2)
        fout.write("Case #" + str(t + 1) + ": " + result + '\n')
        
    fin.close()
    fout.close()
    

def main():
    Run()

if __name__ == "__main__":
    main()
