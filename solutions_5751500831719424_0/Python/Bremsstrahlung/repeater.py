input = open("A-small-attempt1.in")
output = open("output.out","w")
t = int(input.readline())
for i in range(t):
    n = int(input.readline())
    r = 0
    impossible = False
    
    lines = []
    iter = []
    for x in range(n):
        lines.append(input.readline().strip())
        iter.append(0)
    
    seq = ""
    for x in range(len(lines)):
        lineseq = ""
        for y in range(len(lines[x])):
            if len(lineseq) == 0 or lines[x][y] != lineseq[-1]:
                lineseq += lines[x][y]
        if x == 0:
            seq = lineseq
        elif lineseq != seq:
            impossible = True
    
    for x in range(len(seq)):
        ns = []
        for y in range(len(lines)):
            ns.append(0)
            if iter[y] >= len(lines[y]):
                impossible = True
                break
            if lines[y][iter[y]] == seq[x]:
                while True:
                    if lines[y][iter[y]] == seq[x]:
                        ns[y] += 1
                        iter[y] += 1
                    else:
                        break
                    if iter[y] >= len(lines[y]):
                        break
            else:
                impossible = True
                break
        
        if not impossible:
            op = []
            for y in range(len(ns)):
                q = 0
                for z in range(len(ns)):
                    if z != y:
                        q += abs(ns[y] - ns[z])
                op.append(q)
            r += min(op)
    if impossible:
        output.write("Case #{}: Fegla Won\n".format(i + 1))
        print("Case #{}: Fegla Won".format(i + 1))
    else:
        output.write("Case #{}: {}\n".format(i + 1,r))
        print("Case #{}: {}".format(i + 1,r))

output.close();
input.close()
