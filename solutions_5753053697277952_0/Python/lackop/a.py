f = open('A-small-attempt0.in', 'r')
out = open('A-small.txt', 'w')
T = int(f.readline())

for case in range(T):
    N = int(f.readline())
    P = list(map(int, f.readline().strip().split()))
    suma = sum(P)

    end = False

    if suma % 2 == 1:
        maxP = P[0]
        maxI = 0
        for i in range(len(P)):
            if P[i] > maxP:
                maxI = i
                maxP = P[i]

        P[maxI] -= 1
        output = " " + chr(maxI + 65)
    else:
        output = ""

    while not end:

        maxP = P[0]
        maxI = 0
        for i in range(len(P)):
            if P[i] > maxP:
                maxI = i
                maxP = P[i]

        if maxP == 0:
            end = True
            break

        P[maxI] -= 1

        maxP = P[0]
        maxJ = 0
        for i in range(len(P)):
            if P[i] > maxP:
                maxJ = i
                maxP = P[i]

        P[maxJ] -= 1
        output += " " + chr(maxI + 65) + chr(maxJ + 65)

    out.write("Case #" + str(case + 1) + ":" + output + "\n")