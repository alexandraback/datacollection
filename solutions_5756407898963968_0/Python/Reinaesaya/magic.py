# Sean Liu
# Magic Trick

f = open("A-small-attempt0.in", "r")
g = open("output.txt", "w")

T = int(f.readline())

for i in range(T):
    firstrow = []
    secondrow = []
    
    firstprompt = f.readline()
    for j in range(4):
        if (j+1) == int(firstprompt):
            firstrow = f.readline().split()
        else:
            f.readline()

    secondprompt = f.readline()
    for j in range(4):
        if (j+1) == int(secondprompt):
            secondrow = f.readline().split()
        else:
            f.readline()

    num = set(firstrow) & set(secondrow)
    if len(num) < 1:
        g.write("Case #{}: Volunteer cheated!\n".format(i+1))
    elif len(num) > 1:
        g.write("Case #{}: Bad magician!\n".format(i+1))
    else:
        g.write("Case #{}: {}\n".format(i+1, num.pop()))

f.close()
g.close()
