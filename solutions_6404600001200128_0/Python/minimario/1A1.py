inFile = open("A-small-attempt2.in", 'r')
outFile = open('outputx.txt', 'w')
lines = []
for i in inFile:
    i.strip
    lines.append(list(map(int, i.split(' '))))

a = lines[0][0]
lines = lines[1:]
for __ in range(a):
    x = lines[2*__][0]
    y = lines[2*__+1]

    one = 0
    for i in range(len(y)-1):
        if y[i+1]<y[i]:
            one += y[i]-y[i+1]
    two = 0
    xxx = 0
    tot = 0
    for i in range(len(y)-1):
        xxx = max(xxx, y[i]-y[i+1])
    for i in range(len(y)-1):
        if y[i]<=xxx:
            tot += y[i]
        else:
            tot += xxx
    outFile.write("Case #" + str(__+1) + ': '+str(one) + " " + str(tot)+'\n')
inFile.close()
outFile.close()
