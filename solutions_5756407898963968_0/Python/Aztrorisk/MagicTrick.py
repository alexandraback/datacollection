from math import *


in1 = open("C:\\Users\\Hoa\\Dropbox\\Programs\\Python\\GoogleCodeJam2014\\A-small-attempt0.in");

lines = [line for line in in1]

for i in range(int(lines[0])):
    r1 = int(lines[i * 10 + 1])
    row1 = [int(l) for l in lines[i * 10 + 1 + r1].split()]
    r2 = int(lines[i * 10 + 6])
    row2 = [int(l) for l in lines[i * 10 + 6 + r2].split()]
    same = set(row1) & set(row2)
    if len(same) == 1:
        print "Case #%d: %d"%(i + 1, same.pop())
    elif len(same) > 1:
        print "Case #%d: Bad magician!"%(i + 1)
    else:
        print "Case #%d: Volunteer cheated!"%(i + 1)
