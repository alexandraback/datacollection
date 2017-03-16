fin = open("../../Downloads/C-small-attempt1.in", "r")
out = open("logging.out", "w")

cases = int(fin.readline())

for i in range(cases):
    trees = int(fin.readline())
    points = []
    for j in range(0, trees):
        x, y = [int(x) for x in fin.readline().split()]
        points.append((x, y))
    out.write("Case #%d:\n" % (i + 1))
    for a in range(0, trees):
        least = 1000
        if trees <= 2:
            least = 0
        for b in range(0, trees):
            if a == b:
                continue
            pos = 0
            neg = 0
            for c in range(0, trees):
                if a == b or b == c or a == c:
                    continue
                s = points[a][0] * points[b][1] + points[b][0] * points[c][1]
                s += points[c][0] * points[a][1] - points[a][1] * points[b][0]
                s -= points[b][1] * points[c][0] + points[c][1] * points[a][0]
                if s < 0:
                    neg = neg+1
                if s > 0:
                    pos = pos+1
            toCut = min(pos, neg)
            if toCut < least:
                least = toCut
        out.write("%d\n" % least)
out.close()
