#! /usr/bin/env python

import sys
try: 
    in_file = open(sys.argv[1], "r")
except:
    sys.exit("ERROR: input file.")

out_file = open("magicout.txt", "w")

N = int(in_file.readline())

for i in range(N):
    count = [0 for x in range(17)]
    ans = 0
    ansnum = 0
    for t in range(2):
        a = int(in_file.readline())
        for j in range(4):
            line = in_file.readline()
            if j != a-1:
                continue
            else:
                ints = map(int, line.split(' '))
                for k in ints:
                    count[k] += 1
                    if count[k] >= 2:
                        ansnum += 1
                        ans = k

    out_file.write("Case #" + str(i+1) + ": ")
    if ansnum == 0:
        out_file.write("Volunteer cheated!\n")
    elif ansnum == 1:
        out_file.write(str(ans) + "\n")
    else:
        out_file.write("Bad magician!\n")
