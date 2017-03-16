def solve(file):
    f = open(file,'r')
    lines = f.readlines()
    nCases = int(lines[0])
    outf = open("output.txt",'w')
    i = 1
    n = 1
    while nCases > 0:
        a1 = int(lines[i])
        poss1 = lines[i+a1].replace('\n', "").split(" ")
        a2 = int(lines[i+5])
        poss2 = lines[i+5+a2].replace('\n', "").split(" ")
        print(a1, poss1, "\n", a2, poss2)
        intersection = list(set(poss1) & set(poss2))
        print(intersection)
        outf.write("Case #" + str(n) +": ")
        
        if len(intersection) == 1:
            outf.write(intersection[0]+"\n")
        elif len(intersection) == 0:
            outf.write("Volunteer cheated!\n")
        else:
            outf.write("Bad magician!\n")
        i += 10
        nCases -= 1
        n+=1
    f.close()
    outf.close()
