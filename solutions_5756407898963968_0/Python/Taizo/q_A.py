
# -*- coding: cp932 -*-

import sys

inputfile = "A-small-attempt0.in"
f = open(inputfile)
sys.stdout = open(inputfile.replace(".in", ".txt"),'w')
tc_num = int(f.readline().rstrip())

for tc in range(tc_num):
    r = [0 for i in range(2)]
    m = [[[0 for k in range(4)] for j in range(4)] for i in range(2)]
    for i in range(2):
        r[i] = int(f.readline().rstrip()) - 1
        for j in range(4):
            l = f.readline().split()
            for k in range(4):
                m[i][j][k] = int(l[k])

    ans = "Volunteer cheated!"
    same = 0
    for j in range(4):
        for k in range(4):
            if m[0][r[0]][j] == m[1][r[1]][k]:
                same += 1                
                if same > 1:
                    ans = "Bad magician!"
                    break
                ans = str(m[0][r[0]][j])
        if same > 1:
            break
                
    print("Case #" + str(tc+1) + ": " + ans)

   
