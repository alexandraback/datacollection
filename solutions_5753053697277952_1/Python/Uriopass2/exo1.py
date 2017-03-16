def toChar(value):
    return chr(ord('A')+value)

f = open("A-large.in")
tests = int(f.readline())
for t in range(tests):
    parties = int(f.readline())
    counts = [int(x) for x in f.readline().split(" ")]
    toPrint = "Case #%d: "%(t+1);
    while(sum(counts) > 0):
        index = counts.index(max(counts))
        toPrint += toChar(index)
        counts[index] -= 1
        if(sum(counts) != 0 and max(counts)/sum(counts) <= .5):
            toPrint += " "
    print(toPrint)

