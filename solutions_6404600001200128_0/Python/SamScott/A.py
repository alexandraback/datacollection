infile = open('A-small-attempt0.in','r')
outfile = open('output.txt', 'w')

T = int(infile.readline().strip())
out = ""
for tc in range(T):
    out += "Case #"+str(tc+1)+": "
    
    #solution here
    N = int(infile.readline().strip())
    ms = infile.readline().strip().split()
    for i in range(len(ms)):
        ms[i] = int(ms[i])
    #method 1
    prev = ms[0]
    mushcount = 0
    for i in range(1,len(ms)):
        if ms[i] < prev:
            mushcount += prev-ms[i]
        prev = ms[i]
    out += str(mushcount)+" "
    
    # method 2
    rate = 0
    for i in range(1,len(ms)):
        if ms[i-1]-ms[i] > rate:
            rate = ms[i-1]-ms[i]
    mushcount = 0
    for i in range(0,len(ms)-1):
        if ms[i] < rate:
            mushcount += ms[i]
        else:
            mushcount += rate
            
    out += str(mushcount)
    
    out += "\n"
    
print(out)
outfile.write(out)
    
outfile.close()
infile.close()