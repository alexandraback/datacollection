infile = open("B-small-attempt3.in", "r")
outfile = open("output1.txt", "a")

cases = int(infile.readline())

def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

for i in range(1, cases+1):
    line = infile.readline()[:-1].split()
    B = int(line[0])
    N = int(line[1])
    time = infile.readline()[:-1].split()
    sortedtime = sorted(list(map(int, time)))
    count = 0
    barber = []
    a = 1
    for h in range(len(time)):
        barber.append(h+1)
        a = lcm(a, int(time[h]))
    for j in range(1, a):
        for h in range(len(time)):
            if j % int(time[h]) == 0:
                barber.append(h+1)
    if N%len(barber) == 0:
        outfile.write("Case #" + str(i) + ": " + str(barber[-1]) + "\n")
    else:
        outfile.write("Case #" + str(i) + ": " + str(barber[((N%len(barber))-1)]) + "\n")
    

infile.close()
outfile.close()

