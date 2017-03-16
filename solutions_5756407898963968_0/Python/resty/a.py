f = open('A-small-attempt0.in')

def readset():
    row = int(f.readline())
    rows = []
    for i in range(4):
        rows.append(f.readline())
    return map(int, rows[row-1].split(' '))

def solve():
    s1 = readset()
    s2 = readset()
    ans = []
    for i in range(16):
        if (i+1) in s1 and (i+1) in s2:
            ans.append(i + 1)
    if len(ans) == 1:
        return str(ans[0])
    elif len(ans) == 0:
        return "Volunteer cheated!"
    else:
        return "Bad magician!"

    

cases = int(f.readline())
for ct in range(cases):
    print "Case #%d: %s" % (ct + 1, solve())
