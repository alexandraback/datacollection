#default gcj in file reader
#Boreeas, 7/3/2012

fin = open("in")
fout = open("out", "w")
case = 0

def wrt(out):
    global case
    case += 1
    fout.write("Case #" + str(case) + ": " + str(out) + "\n")

def solve(strings):
    sequences = []
    for s in strings:
        last = s[0]
        count = 1
        subseq = []
        for c in s[1:]:
            if c == last:
                count += 1
            else:
                subseq.append((last, count))
                count = 1
                last = c
        subseq.append((last, count))
        sequences.append(subseq)

    for subseq in sequences:
        if len(subseq) != len(sequences[0]):
            wrt("Fegla Won")
            return
        for i in range(len(subseq)):
            if subseq[i][0] != sequences[0][i][0]:
                wrt("Fegla Won")
                return

    median = []
    for i in range(len(sequences[0])):
        counts = [subseq[i][1] for subseq in sequences]
        counts.sort()
        median.append(counts[len(counts) // 2])

    operations = 0
    for subseq in sequences:
        for i in range(len(subseq)):
            operations += abs(subseq[i][1] - median[i])

    wrt(operations)
        

    

fin.readline()  #skip number-of-cases
while 1:
    line = fin.readline().rstrip()
    if not line:
        break
    strings = []
    for i in range(int(line)):
        strings.append(fin.readline().rstrip())

    solve(strings)
    

#release handles
fin.close()
fout.close()
