__author__ = 'zoli'


def solve(filnIn, filnOut):
    f = open(filnIn)
    fOut = open(filnOut, "w")
    T = int(f.readline())
    for i in range(T):
        irow1 = int(f.readline())
        rgRows1 = []
        for rowT in range(4):
            rgRows1.append([int(n) for n in f.readline().split()])

        irow2 = int(f.readline())
        rgRows2 = []
        for rowT in range(4):
            rgRows2.append([int(n) for n in f.readline().split()])
        hmlPossible = set(rgRows1[irow1 - 1]) & set(rgRows2[irow2 - 1])
        stMsg = "Case #{0}: {1}".format(i + 1, hmlPossible.pop() if len(
            hmlPossible) == 1 else "Volunteer cheated!" if len(hmlPossible) == 0 else "Bad magician!")
        print(stMsg)
        fOut.write(stMsg)
        fOut.write("\n")


if __name__ == "__main__":
    solve("A-small-attempt0.in", "A-small-attempt0.out")