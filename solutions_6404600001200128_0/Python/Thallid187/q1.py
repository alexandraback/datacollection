
f = open('A-small-attempt0.in', 'r')
o = open('out.txt', 'w')
T = f.readline()
T = int(T)
for t in range(1, T+1):
    n = f.readline()
    m = f.readline()
    m = m.split()
    n = int(n)
    m = map(int, m)

    #Get first ans first
    temp = 0
    ansA = 0
    for i in range(0, n):
        if temp > m[i]:
            ansA += (temp - m[i])
        temp = m[i]

    #Get 2nd ans
    maxDiff = 0
    temp = 0
    for i in range(0, n):
        if temp > m[i]:
            maxDiff = max(maxDiff, temp - m[i])
        temp = m[i]    
    ansB = 0
    for i in range(0, n-1):
        ansB += min(maxDiff, m[i])        
                     
    outline = "Case #%d: %d %d\n" % (t, ansA, ansB)
    o.write(outline)

o.close()
