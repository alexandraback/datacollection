fin = open('A.in', 'r')
fout = open('file.out', 'w')
n = fin.readline()
    
for l in range(int(n)):
    g = int(fin.readline())
    groups = map(int,fin.readline().split())
    #print groups
    output = []
    while sum(groups) > 0:
        cur = sorted([[groups[i],i] for i in range(len(groups))],reverse=True)
        #print cur, '*'
        out = [cur[0][1]]
        cur[0][0] -= 1
        #print cur
        cur = sorted(cur,reverse=True)
        #print cur
        if sum([c[0] for c in cur]) != 2:
            out.append(cur[0][1])
        for o in out:
            groups[o] -= 1
        output.append(out)
       # print groups, out
    #print output

    
    fout.write("Case #%d: "%(l+1))
    fout.write(' '.join(map(lambda x: ''.join(map(lambda y:chr(65 + y),x)),output)) + '\n')
        
    
fin.close()
fout.close()
