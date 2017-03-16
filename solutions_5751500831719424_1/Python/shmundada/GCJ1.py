def solve(inp,N):
    patt = []
    for string in inp:
        cont = []
        start = string[0]
        temp = ""
        for e in string:
            if e == start:
                temp += e
                start = e
            else:
                cont.append(temp)
                temp = e
                start = e
        cont.append(temp)
        patt.append(cont)
    parts = len(patt[0])
    for p in patt:
        if len(p) is not parts:
            return "Fegla Won"
    least = 0
    for p in range(parts):
        col = [patt[i][p] for i in range(N)]
        temp = calleast(col)
        if temp == "False":
            return "Fegla Won"
        least += temp
    return str(least)

def calleast(col):
    vect = [len(part) for part in col]
    maxx = max(vect)
    least = 100000
    char = col[0][0]
    for part in col:
        if part[0] is not char:
            return "False"
    for i in range(1,maxx+1):
        temp = 0
        for l in vect:
            temp += abs(l-i)
        if temp < least:
            least = temp
    return least

f = open('A-large.in', 'r')
line1 = f.readline()
cases = int(line1)
for case in range(1,cases+1):
    line = f.readline()
    N = int(line)
    inp = []
    for i in range(N):
        line = f.readline()
        inp.append(line)
    print "Case #"+str(case)+ ": " + solve(inp,N)
