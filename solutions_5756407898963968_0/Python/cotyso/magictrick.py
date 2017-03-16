from __future__ import print_function

outFile = open("magictrick.out", "w")

#lines = list(open("magictrick.in"))
lines = list(open("A-small-attempt0.in"))
testCount = int(lines.pop(0))

for test in range(1, testCount+1):

    row = int(lines.pop(0))
    for i in range(1,5):
        line = lines.pop(0)
        if i == row:
            cards1 = str.split(line)

    row = int(lines.pop(0))
    for i in range(1,5):
        line = lines.pop(0)
        if i == row:
            cards2 = str.split(line)

    intersection = [x for x in cards1 if x in cards2]
    outFile.write("Case #{}: ".format(test))
    if len(intersection) == 0:
        outFile.write("Volunteer cheated!\n")
    elif len(intersection) == 1:
        outFile.write(intersection[0])
        outFile.write("\n")
    else:
        outFile.write("Bad magician!\n")

outFile.close()