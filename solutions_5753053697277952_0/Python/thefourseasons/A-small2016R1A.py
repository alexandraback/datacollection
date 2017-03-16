def split(c):
    data = list()
    finish = False
    d = -1
    e = 0
    while finish == False:
        d = d+1
        e = e+1
        if c[d] == " ":
            data.append(c[d-e+1:d])
            c = c[:d] + "," + c[d:]
            d = d+1
            e = 0
        if d == len(c)-1:
            finish = True
    data.append(c[len(c)-e:])
    return data
def highest(i):
    j = 0
    highest = 0
    for k in range (0,len(i)):
        if i[k]>j:
            j = i[k]
            highest = k
        else:
            continue
    i[highest] = i[highest] - 1
    highest = highest + 65
    highest = chr(highest)
    return str(highest)

with open("A-small2016R1C.in") as z:
    a = z.readline()
    for b in range (0, int(a)):
        q = z.readline()
        g = z.readline()
        r = q
        f = int(r)
        total = 0
        answer = []
        answerstr = ''
        g = split(g)
        for h in range (0,f):
            g[h] = int(g[h])
            total = total + g[h]
        if total % 2==1:
            answer.append(highest(g))
        else:
            pass
        m = total/2
        for n in range (0, int(m)):
            answer.append(highest(g) + highest(g))
        for o in range (0, len(answer)):
            answerstr = answerstr + " " + answer[o]
        print("Case #" + str(b+1) + ": " + answerstr)
