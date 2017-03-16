def solve(file):    
    f = open(file,'r')
    lines = f.readlines()
    nCases = int(lines[0])
    outf = open("output.txt",'w')
    i = 1 # line number
    n = 1 # case number
    while nCases > 0:
        #print("case: " + str(n))
        line = lines[i].replace('\n', "").split(" ")
        N = int(line[0])

        s = []
        c = []
        repl = []
        repn = []
        
        for j in range(0,N):
            line = lines[i+1+j].replace('\n', "").split(" ")
            s.append(line[0])
            c.append(0)
            repl.append('a')
            repn.append(-1)

        #print (s)

        result = "nothing"
        
        moves = 0
        imp = False
        while True:
            for j in range(0,len(s)):
                l = s[j][c[j]]
                count = 0
                while c[j] < len(s[j]) and s[j][c[j]] == l:
                    count += 1
                    c[j]+=1                
                repl[j] = l
                repn[j] = count

            #print(repl)
            #print(repn)
            
            l = repl[0]
            for j in range(1,len(repl)):
                 if repl[j] != l:
                     imp = True
            #print(imp)
            
            if imp==True:
                 break

            repn.sort()
            med = repn[int((len(repn)-1)/2)]
            #print(med)
            
            for j in range(0,len(repn)):
                off = repn[j]-med
                if off < 0:
                    off = -off
                moves += off
            #print(moves)
            
            #check done
            notdone = False            
            done = False
            for j in range(0,len(c)):
                if c[j]==len(s[j]):
                    done = True
                else:
                    notdone = True
            #print(done)
            #print(notdone)
            
            if (done == True and notdone == True):
                imp = True
                break
            if (done == True and notdone == False):
                break

        
        if (imp == True):
            result = "Fegla Won";
        else:
            result = str(moves)

        outf.write("Case #" + str(n) +": " + result + "\n")        

        i += N+1
        nCases -= 1
        n+=1

        
    f.close()
    outf.close()
