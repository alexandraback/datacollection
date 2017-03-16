from math import *
eps = 1e-21
with open("C-small-attempt7.in") as f:
    lines = f.readlines()

outputname = 'outputCsmall7.txt'
f = open(outputname, 'w')

cases = int(lines[0])
linenum = 1

for i in range(cases):
    numtrees = int(lines[linenum])
    linenum += 1

    coords = [(0,0) for j in range(numtrees)]

    for j in range(numtrees):
        nums = lines[linenum]
        linenum += 1

        x, y = [int(k) for k in nums.split(" ")]
        coords[j] = [x,y]

    f.write("Case #" + str(i + 1) + ":\n")
    if numtrees == 1:
        f.write("0\n")
        continue
    for j in range(numtrees):
        angles = [0.0] * (numtrees-1)
        for k in range(numtrees):
            if j != k:
                index = k
                if k > j:
                    index -= 1
                angles[index] = atan2(coords[k][1]-coords[j][1], coords[k][0]-coords[j][0])
        angles.sort()
        offsets = [2*pi + a for a in angles]
        angles = angles + offsets + [1000.0]

        minn = 10000
        end = 0
        for k in range(numtrees):
            while end < numtrees and angles[end] - angles[k] < pi - eps:
                end += 1
            if end >= numtrees:
                break

            val = end - k - 1
            if val < minn:
                minn = val
        f.write(str(minn) + "\n")


    pass


f.close()

with open(outputname, 'r') as f:
    print(f.read())
