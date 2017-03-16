def first(N,mushs):
    total = 0
    for i in range(N-1):
        m1 = mushs[i]
        m2 = mushs[i+1]
        if m1 > m2:
            total += m1-m2
    return total


def second(N, mushs):
    total = 0
    rate = 0
    for i in range(N-1):
        m1 = mushs[i]
        m2 = mushs[i+1]
        if m1> m2:
            newRate = m1-m2            
            if newRate > rate:
                rate = newRate
    for i in range(N-1):
        m1 = mushs[i]
        total += min(m1,rate)
    return total



f = open("one.in", "r").read()

splitted_file = f.split("\n")[:]

lineCounter =1
amountOfLines = len(splitted_file)

case = 0

while(lineCounter < amountOfLines-1):
    case += 1
    firstLine = splitted_file[lineCounter]
    lineCounter += 1

    secondLine = splitted_file[lineCounter]
    lineCounter += 1

    N= int(firstLine)

    mushs = [int(x) for x in secondLine.split(" ")]   
    out1 = first(N,mushs)
    out2 = second(N,mushs)
    print "Case "+ "#"+str(case) +": " + str(out1)+ " "  + str(out2)
    
    
