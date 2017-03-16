def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

fin = open('B-small-attempt3.in', 'r')
fout = open('B-small-attempt3.out', 'w')
T = int(fin.readline())
for t in range(T):
    args = fin.readline().replace("\n", "").split(" ")
    args = map(int, args)
    B = args[0]
    N = args[1]
    print t+1, N
    ms = fin.readline().replace("\n", "").split(" ")
    ms = map(int, ms)
    readytimes = [0 for i in range(len(ms))]
    time = 0
    n = 0
    answer = 0
    LCM = reduce(lcm, ms)
    SUM = reduce((lambda x,y: x+LCM/y), ms, 0)
    SKIP = N/SUM-1
    N = N-SKIP*SUM
    print t+1, LCM, SUM, SKIP, N
    if(N==0):
        answer = 1
    else:
        while(True):
            index = readytimes.index(time)
            readytimes[index] += ms[index]
            time = min(readytimes)
            n += 1
            if(n == N):
                answer = index+1
                break
    fout.write("Case #" + str(t+1) + ": "  + str(answer) + "\n")
fin.close()
fout.close()
print "done!"


        
