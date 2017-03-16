def func(args):
    return args

fin = open('A-small-attempt0.in', 'r')
fout = open('A-small-attempt0.out', 'w')
T = int(fin.readline())
for t in range(T):
    N = int(fin.readline())
    args = fin.readline().replace("\n", "").split(" ")
    args = map(int, args)
    SUM = 0
    MAX = 0
    for i in xrange(len(args)-1):
        VAR = args[i]-args[i+1]
        if(VAR > 0):
            SUM += VAR
            if(VAR > MAX):
                MAX = VAR
    fout.write("Case #" + str(t+1) + ": "  + str(SUM) + " " + str(MAX*(N-1)) + "\n")
fin.close()
fout.close()


        
