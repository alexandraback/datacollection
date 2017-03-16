"""
Google Code Jam
Online Qualifying Round

Problem A - Magic Trick
"""
# Read the size
infile = open('A-small-attempt1.in')
cases = int(infile.readline())

# Make an outfile
outfile = open('A-small-attempt1.out', 'w')

for case in range(cases):
    # Make a set containing the ints in the specified row
    first_row = int(infile.readline())
    first_poss = set()
    for i in range(4):
        if first_row == i+1:
            for x in [int(x) for x in infile.readline().split()]:
                first_poss.add(x)
        else:
            infile.readline()
    
    # Make another set for the second instance
    second_row = int(infile.readline())
    second_poss = set()
    for i in range(4):
        if second_row == i+1:
            for x in [int(x) for x in infile.readline().split()]:
                second_poss.add(x)
        else:
            infile.readline()
    
    total_poss = first_poss.intersection(second_poss)
    
    outfile.write("Case #" + str(case+1) + ": ")
    if len(total_poss) == 1:
        # Magician got it right!
        outfile.write(str(total_poss.pop()) + '\n')
    elif len(total_poss) == 0:
        # No possibilities, volunteer messed up!
        outfile.write("Volunteer cheated!\n")
    else:
        # Magician messed up
        outfile.write("Bad magician!\n")