infile = open('Ain.txt', 'r')
outfile = open('Aout.txt', 'w')

raw = infile.readline()
t = int(raw.rstrip())
for z in range(1, t+1):
    startrow = infile.readline()
    startrow = int(startrow.rstrip())
    startgrid =[]
    endgrid=[]
    for i in range(0, 4):
        raw = infile.readline()
        raw = raw.split()
        raw = [int (i) for i in raw]
        startgrid.append(raw)
    endrow = infile.readline()
    endrow = int(endrow.rstrip())
    for i in range(0, 4):
        raw = infile.readline()
        raw = raw.split()
        raw = [int (i) for i in raw]
        endgrid.append(raw)
    lookatstart = startgrid[startrow-1]
    lookatend = endgrid[endrow-1]
    intersect=[]
    for each in lookatstart:
        if each in lookatend:
            intersect.append(each)
    if len(intersect)==1:
        outline = "Case #"+str(z)+": "+str(intersect[0])+"\n"
    elif len(intersect)>1:
        outline = "Case #"+str(z)+": Bad magician!"+"\n"
    else:
        outline = "Case #"+str(z)+": Volunteer cheated!"+"\n"
    outfile.write(outline)
outfile.close()
