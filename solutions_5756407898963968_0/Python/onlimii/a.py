#!/usr/bin/env python

with open("A-small-attempt0.in", "r") as fin:
    N = int(fin.readline())
    fout = open("A-small-attempt0.out", "w")

# read the input
    for i in xrange(N):
        row = int(fin.readline())
        for n in range(4):
            row_temp = fin.readline()
            if n + 1 == row:
                row1 = row_temp.split()
        row = int(fin.readline())
        for n in range(4):
            row_temp = fin.readline()
            if n + 1 == row:
                row2 = row_temp.split()
        choose = set(row1) & set(row2)
        fout.write("Case #" + str(i+1) + ": ")
        if len(choose) == 1:
            fout.write(str(list(choose)[0]) + "\n")
        elif len(choose) == 0:
            fout.write("Volunteer cheated!\n")
        else:
            fout.write("Bad magician!\n")
fin.close()
fout.close()


