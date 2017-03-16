inp = open("A-large.in", "r")
outfile = open("out1.txt", "w")
cases = int(inp.readline())
for i in range(cases):
    parties = int(inp.readline())
    res = []
    amounts = list(map(int,inp.readline().split()))
    totalPresent = sum(amounts)
    while totalPresent > 0:
        m = max(amounts)
        index1 = amounts.index(m)
        amounts[index1] -= 1
        totalPresent -= 1
        index2 = -1
        if totalPresent > 0 and totalPresent != 2:
            m = max(amounts)
            index2 = amounts.index(m)
            amounts[index2] -= 1
            totalPresent -= 1
        r = chr(65+index1)
        if index2 != -1:
            r += chr(65+index2)
        res.append(r)
    print(i)
    outfile.write("Case #" + str(i+1) + ": " + " ".join(res) + "\n")