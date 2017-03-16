import os, re

f = open('problem1.txt', 'r')

numproblems = int(f.readline())

outf = open('out1.txt', 'w')

for problemnum in range(numproblems):
    guess1 = int(f.readline()) - 1

    grid1 = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
    for i in range(4):
        gridline = f.readline()
        gridline = re.sub('\n', '', gridline)
        gridline = gridline.split()
        
        grid1[i][0] = int(gridline[0])
        grid1[i][1] = int(gridline[1])
        grid1[i][2] = int(gridline[2])
        grid1[i][3] = int(gridline[3])

    guess2 = int(f.readline()) - 1

    grid2 = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
    for i in range(4):
        gridline = f.readline()
        gridline = re.sub('\n', '', gridline)
        gridline = gridline.split()
        
        grid2[i][0] = int(gridline[0])
        grid2[i][1] = int(gridline[1])
        grid2[i][2] = int(gridline[2])
        grid2[i][3] = int(gridline[3])

    #get possible values for grid1
    possible1 = grid1[guess1]
    possible2 = grid2[guess2]

    numfound = 0
    value = 0
    
    for i in possible1:
        if i in possible2:
            numfound = numfound + 1
            value = i
            

    if numfound == 1:
        msg = 'Case #' + str(problemnum + 1) + ': ' + str(value) + ''
    elif numfound == 0:
        msg = 'Case #' + str(problemnum + 1) + ': Volunteer cheated!'
    else:
        msg = 'Case #' + str(problemnum + 1) + ': Bad magician!'
    print msg
    outf.write(msg + '\n')

f.close()
outf.close()
