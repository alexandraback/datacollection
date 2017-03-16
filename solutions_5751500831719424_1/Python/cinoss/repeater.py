import sys
fname = "A-small-attempt0.in"
fname = "A-large.in"
# fname = "A-large-practice.in"
# fname = "sample.in"
fi = open(fname)
fo = open("fo.txt", "w")
# fo = sys.stdout
for test in range(int(fi.readline())):
    n = int(fi.readline().strip())
    a = []
    possible = True
    print n
    prev = None
    for i in range(n):
        s = fi.readline().strip()
        print s
        curr = ""
        i = 0
        while len(s) > 0:
            if len(a) <= i:
                a.append([])
            c = s[0]
            curr += c
            count = 0
            while len(s) > 0 and s[0] == c:
                count += 1
                s = s[1:]
            a[i].append(count)
            i += 1
        # a.append(x)
        if prev and prev != curr:
            possible = False
            # break
        prev = curr
    if possible:
        ret = 0
        for x in a:
            # print x
            xmin = min(x)
            xmax = max(x)
            y = []
            for i in range(xmin, xmax + 1):
                t = 0
                for j in x:
                    t += abs(i - j)
                # print i, t
                y.append(t)
            # print y
            ret += min(y)
        print >>fo, "Case #%d: %d" % (test + 1, ret)
    else:
        print >>fo, "Case #%d: Fegla Won" % (test + 1)
