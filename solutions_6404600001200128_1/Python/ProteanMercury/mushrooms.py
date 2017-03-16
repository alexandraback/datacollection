def func(args):
    return args

fin = open('A-large.in', 'r')
fout = open('A-large.out', 'w')
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
    SECOND = 0
    for i in xrange(len(args)-1):
        if(args[i] > MAX):
            SECOND += MAX
        else:
            SECOND += args[i]
    fout.write("Case #" + str(t+1) + ": "  + str(SUM) + " " + str(SECOND) + "\n")
fin.close()
fout.close()


        
