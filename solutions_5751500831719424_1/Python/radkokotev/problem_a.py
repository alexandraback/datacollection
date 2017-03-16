filename = raw_input("Name of file: ")
f = open(filename, "r")
o = open(filename + ".out", "w")


T = int(f.readline()[:-1])

## Code starts here

def getchset(s):
    chset = s[0]
    for c in s:
        if c != chset[-1]:
            chset += c
    return chset

def getchlist(s):
    chlist = [[s[0],0]]
    for c in s:
        if c == chlist[-1][0]:
            chlist[-1][1] += 1
        else:
            chlist += [[c,0]]
    return chlist

for t in range(1, T + 1):
    n = int(f.readline()[:-1])
    ss = []
    for i in range(n):
        ss += [f.readline()[:-1]]
        
    chset = getchset(ss[0])

        
    possible = True
    
    for s in ss:
        if getchset(s) != chset:
            possible = False
            break
                
        
    if not possible:            
        o.write("Case #%d: Fegla Won\n" %(t))
        continue

    for i in range(n):
        ss[i] = getchlist(ss[i])

    total = 0
    for i in range(len(ss[0])):
        m = 100000
        count = 0
        for j in range(0,101):
            temps = 0
            for s in ss:
                cur = s[i]
                #print cur
                temps += abs(cur[1] - j)
            if temps < m:
                m = temps
                count = j
        total += m
    o.write("Case #%d: %d\n" %(t, total))            
    
## code ends here

o.close()
f.close()
