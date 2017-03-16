def main():
    fin = file("A-small-attempt0.in","r")
    t = int(fin.readline())
    fout = file("A-small.out", "w")
    for i in range(t):
        firstRow = int(fin.readline());
        for j in range(4):
            scanf = fin.readline().split();
            if (j == (firstRow - 1)):
                a = scanf[:]
        secondRow = int(fin.readline());
        for j in range(4):
            scanf = fin.readline().split();
            if (j == (secondRow - 1)):
                b = scanf[:]
        c = set(a) & set(b)
        if len(c) == 0:
            output = "Case #" + str(i + 1) + ": " + "Volunteer cheated!\n"
        if len(c) >1:
            output = "Case #" + str(i + 1) + ": " + "Bad magician!\n"
        if len(c) == 1:
            output = "Case #" + str(i + 1) + ": " + str(c.pop()) + '\n'
        fout.write(output);
if __name__ == '__main__':
    main()
