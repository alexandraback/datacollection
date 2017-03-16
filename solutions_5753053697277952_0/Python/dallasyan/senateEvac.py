with open("inp.txt") as f:
    with open("out.txt","w+") as g:
        lcounter = 0
        arr=[]
        numP=0
        for i in range(26):
            arr.append(0)
        for line in f:
            numPolis=0
            line=line.strip()
            if lcounter > 0:
                if lcounter%2 == 1:
                    numP=int(line)
                    if lcounter>1:
                        g.write("\n")
                elif lcounter%2 == 0:
                    g.write("Case #"+str(int(lcounter/2))+": ")
                    line=line.split()
                    for i in range(len(line)):
                        line[i]=int(line[i])
                    for i in range(len(line)):
                        numPolis+=int(line[i])
                while numPolis>0:
                    j=-1
                    k=-1
                    if max(line) > sum(line)/2-1 and max(line)!=1:
                        for i in range(len(line)):
                            if line[i]==max(line):
                                if j==-1:
                                    j=i
                                else:
                                    k=i
                    elif max(line)==1 and numPolis==2:
                        for i in range(len(line)):
                            if line[i]==max(line):
                                if j==-1:
                                    j=i
                                else:
                                    k=i
                    else:
                        for i in range(len(line)):
                            if line[i]==min(line):
                                    j=i
                    line[j]-=1
                    numPolis-=1
                    g.write(str(chr(ord('A')+j)))
                    
                    if k!=-1:
                        line[k]-=1
                        numPolis-=1
                        g.write(str(chr(ord('A')+k)))
                    if numPolis>0:
                        g.write(" ")                          
            lcounter+=1
