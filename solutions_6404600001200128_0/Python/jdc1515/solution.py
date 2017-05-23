with open("A-small-attempt0.in") as f:
    lines = f.readlines()

outputname = 'outputAsmall.txt'
f = open(outputname, 'w')

cases = int(lines[0])
linenum = 1

for i in range(cases):
    count = int(lines[linenum])
    linenum += 1

    nums = lines[linenum].split(" ")
    nums = [int(j) for j in nums]
    linenum += 1

    y = 0
    lastmax = nums[0]
    for j in nums:
        if j < lastmax:
            y += lastmax - j
        lastmax = j

    maxrate = 0
    last = nums[0]
    for j in nums:
        diff = last - j
        if diff > maxrate:
            maxrate = diff
        last = j
    numeaten = 0
    for j in nums[:-1]:
        numeaten += min(j, maxrate)
    z = numeaten

    f.write("Case #" + str(i+1) + ": " + str(y) + " " + str(z) + "\n")


f.close()

with open(outputname, 'r') as f:
    print(f.read())
