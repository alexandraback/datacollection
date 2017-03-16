import os
os.chdir('C:\\Users\Xueying\Desktop\Google Code Jam 2015\Round1B')

from math import *
from itertools import *




def calculate(l, r, c):
    score = 0
    for i in range(r):
        for j in range(c):
            cur = l[i][j]
            if cur==0:
                continue
            if i+1 < r and l[i+1][j] == 1:
                score += 1
            if j+1 < c and l[i][j+1] == 1:
                score += 1
    return score




inpfile = open("B-small-attempt0.in", 'r')
outfile = open('out_b.txt.', 'w')
casenum = int(inpfile.readline().strip())
for case in range(1, casenum + 1):
    line = inpfile.readline().strip()
    linelst = line.split()
    r = int(linelst[0])
    c = int(linelst[1])
    n = int(linelst[2])
    prod = r*c
    minScore = 99999999

    d1l = range(prod)
    for e in combinations(d1l, n):
        # print e

        l = []
        for i in range(r):
            temp = []
            for j in range(c):
                temp.append(0)
            l.append(temp)

        for idx in e:
            x = idx / c
            y = idx % c
            # print x 
            # print y
            l[x][y] = 1
        # print l
        score = calculate(l, r, c)
        # print score
        minScore = min(score, minScore)
    

    # print linelst
    # print d1l

    result = "Case #" + str(case) + ": " + str(minScore) + "\n"
    print result
    outfile.write(result)
inpfile.close()
outfile.close()

# for e in combinations('ABCD', 2):
#     print e



    