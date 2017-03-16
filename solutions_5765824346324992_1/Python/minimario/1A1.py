from fractions import gcd
def lcm(a, b): return a*b//gcd(a, b)

inFile = open("B-large.in", 'r')
outFile = open('outputx.txt', 'w')
lines = []
for i in inFile:
    i.strip
    lines.append(list(map(int, i.split(' '))))
tc=lines[0][0]
lines = lines[1:]
for iasdf in range(tc):
    n, m = lines[2*iasdf][0], lines[2*iasdf][1]
    cut = lines[2*iasdf+1]
    x=(m-1) / sum([1/(tt+0.0) for tt in cut])
    curr = 0

    x=int(x)
    dead = False
    key = 0
    lcmx=1
    for i in cut:
        lcmx=lcm(lcmx, i)
        if lcmx >= 1000000000:
            lcmx=1
            break
    ######    
    print(x, cut, m, curr)
    ###
    mult = x // lcmx
    x = mult * lcmx
    for i in cut:
        curr += x // i
    while not curr >= m:
        for i in range(len(cut)):
            if x%cut[i] == 0:
                curr += 1
                if curr == m:
                    key = i+1

                    

        x+=1
    print(iasdf+1)
    outFile.write("Case #" + str(iasdf+1) + ": " + str(key) + "\n")
inFile.close()
outFile.close()
