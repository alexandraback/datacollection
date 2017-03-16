#default gcj in file reader
#Boreeas, 7/3/2012
fin = open("in")
fout = open("out", "w")
case = 0

def wrt(out):
    global case
    case += 1
    fout.write("Case #" + str(case) + ": " + str(out) + "\n")

fin.readline()  #skip number-of-cases
while 1:
    line = fin.readline().rstrip()
    if not line:
        break
    # Hook here
    c1 = int(line) - 1
    grid1 = [
        [int(x) for x in fin.readline().rstrip().split()],
        [int(x) for x in fin.readline().rstrip().split()],
        [int(x) for x in fin.readline().rstrip().split()],
        [int(x) for x in fin.readline().rstrip().split()]
        ]
    c2 = int(fin.readline().rstrip()) - 1
    grid2 = [
        [int(x) for x in fin.readline().rstrip().split()],
        [int(x) for x in fin.readline().rstrip().split()],
        [int(x) for x in fin.readline().rstrip().split()],
        [int(x) for x in fin.readline().rstrip().split()]
        ]

    result = [x for x in grid2[c2] if x in grid1[c1]]
    if len(result) == 0:
        wrt("Volunteer cheated!")
    elif len(result) == 1:
        wrt(result[0])
    else:
        wrt("Bad magician!")




#release handles
fin.close()
fout.close()
