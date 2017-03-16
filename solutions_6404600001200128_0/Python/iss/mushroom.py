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

def simpleshroom(m):
    shrooms = 0
    
    for a in range(len(m)-1):
        if m[a] > m[a+1]:
            shrooms += m[a] - m[a+1]

    return shrooms

def complexshroom(m):
    largestdiff = 0
    
    for a in range(len(m)-1):
        if (m[a] - m[a+1]) > largestdiff:
            largestdiff = m[a] - m[a+1]

    shrooms = 0
    
    for a in range(len(m)-1):
        shrooms += min(m[a], largestdiff)

    return shrooms

cases = int(inp.readline().strip())

for r in range(cases):

    n = single()
    m = multint()

    res1 = simpleshroom(m)
    res2 = complexshroom(m)

    print("Case #" + str(r+1) + ": " + str(res1) + " " + str(res2))
    out.write("Case #" + str(r+1) + ": " + str(res1) + " " + str(res2) + "\n")    

inp.flush()
out.flush()
inp.close()
out.close()
