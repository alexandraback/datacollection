fin = open("../../Downloads/A-large (2).in", "r")
out = open("mushrooms.out", "w")

cases = int(fin.readline())

for i in range(cases):
    n = int(fin.readline())
    list = [int(x) for x in fin.readline().split()]
    tot = 0;
    maxDiff = 0;
    for j in range(1, n):
        diff = list[j-1] - list[j]
        if list[j-1] > list[j]:
            tot += diff
        if diff > maxDiff:
            maxDiff = diff
    tot2 = 0
    for x in list:
        tot2 += min(maxDiff, x)
    tot2 -= min(maxDiff, list[n-1])
    out.write("Case #%d: %d %d\n" % (i + 1, tot, tot2))
out.close()
