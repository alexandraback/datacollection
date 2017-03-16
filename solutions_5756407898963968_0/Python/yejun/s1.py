import sys

def readone(f):
    guess = int(f.readline().strip())
    lines = []
    for i in range(4):
        lines.append([int(j) for j in f.readline().strip().split()])
    return guess, lines

with open(sys.argv[1]) as f:
    total = int(f.readline().strip())
    for i in range(total):
        g1, m1 = readone(f)
        g2, m2 = readone(f)
        a = set(m1[g1-1]).intersection(set(m2[g2-1]))
        sys.stdout.write("Case #%d: " % int(i+1))
        if len(a) == 1:
            print(a.pop())
        elif len(a) == 0:
            print("Volunteer cheated!")
        else:
            print("Bad magician!")

