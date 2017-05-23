with open("B-small-attempt0.in") as f:
    lines = f.readlines()

outputname = 'outputBsmall.txt'
f = open(outputname, 'w')

cases = int(lines[0])
linenum = 1

def minstocount(M, mins):
    if mins == -1:
        return 0
    count = len(M)
    for i in M:
        count += mins / i
    return count

for i in range(cases):
    inputnums = lines[linenum]
    linenum += 1
    B, N = [int(j) for j in inputnums.split(" ")]

    M = lines[linenum]
    M = [int(j) for j in M.split(" ")]
    linenum += 1

    count = 0
    mins = 1
    while count < N:
        mins *= 2
        count = minstocount(M, mins)

    high = mins
    low = mins / 2
    gap = mins / 4

    while gap > 4:
        mid = high - gap
        count = minstocount(M, mid)
        if count >= N:
            high = mid
        else:
            low = mid
        gap /= 2
    mins = high

    count = N
    while count >= N:
        mins -= 1
        count = minstocount(M, mins)
    mins += 1
    oldcount = count
    count = minstocount(M, mins)
    diff = N - oldcount

    for j in range(len(M)):
        if (mins % M[j]) == 0:
            diff -= 1
        if diff == 0:
            f.write("Case #" + str(i + 1) + ": " + str(j+1) + "\n")
            break
    pass


f.close()

with open(outputname, 'r') as f:
    print(f.read())
