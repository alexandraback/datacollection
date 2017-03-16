inp = open('A-small.in', 'r')
out = open('A-small.out', 'w')

def single():
    return inp.readline().strip()

def mult():
    return inp.readline().strip().split()

def multint():
    x = inp.readline().strip().split()
    for a in range(len(x)):
        x[a] = int(x[a])
    return x

cases = int(inp.readline().strip())

for r in range(cases):

    n = int(single())
    a = single()
    b = single()

    y = 0

    if len(a) > len(b):
        temp = a
        a = b
        b = temp

    alet = []
    alen = [0]
    blet = []
    blen = [0]

    currentlet = a[0]
    alet.append(currentlet)

    for x in a:
        if x == currentlet:
            alen[len(alet)-1] += 1
        else:
            currentlet = x
            alet.append(currentlet)
            alen.append(1)

    currentlet = b[0]
    blet.append(currentlet)

    for z in b:
        if z == currentlet:
            blen[len(blet)-1] += 1
        else:
            currentlet = z
            blet.append(currentlet)
            blen.append(1)

    if alet != blet:
        y = -1
    else:
        for x in range(len(alen)):
            y += abs(alen[x] - blen[x])

    
    if y == -1:
        print("Case #" + str(r+1) + ": " + "Fegla Won")
        out.write("Case #" + str(r+1) + ": " + "Fegla Won" + "\n")
    else:
        print("Case #" + str(r+1) + ": " + str(y))
        out.write("Case #" + str(r+1) + ": " + str(y) + "\n")

inp.flush()
out.flush()
inp.close()
out.close()
