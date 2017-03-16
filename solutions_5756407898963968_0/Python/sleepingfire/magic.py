import sys

path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
file = open(path, "r")
T = int(file.readline())

for i in range(T):
    a1 = int(file.readline()) - 1
    for j in range(4):
        line = file.readline()
        if j == a1:
            set1 = set(int(z) for z in line.split())

    a2 = int(file.readline()) - 1
    for j in range(4):
        line = file.readline()
        if j == a2:
            set2 = set(int(z) for z in line.split())

    inter = set1.intersection(set2)
    if len(inter) == 1:
        text = str(inter.pop())
    elif len(inter) == 0:
        text = "Volunteer cheated!"
    else:
        text = "Bad magician!"
    
    print("Case #%d: %s"%(i+1, text))
