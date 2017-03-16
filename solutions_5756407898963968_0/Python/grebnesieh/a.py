input = open("a.in" , "r")
output = open("a.out" , "w")
T = int(input.readline())
for i in range(1, T + 1):
    f = int(input.readline())
    A = [map(int, input.readline().split(" ")) for j in range(4)]
    s = int(input.readline())
    B = [map(int, input.readline().split(" ")) for j in range(4)]
    a = []
    for x in A[f - 1]:
        for y in B[s - 1]:
            if x == y:
                a.append(y)
    print "Case #" + str(i) + ":",
    output.write("Case #" + str(i) + ": ")
    if len(a) == 1:
        print str(a[0])
        output.write(str(a[0]) + "\n")
    elif len(a) == 0:
        print "Volunteer cheated!"
        output.write("Volunteer cheated!\n")
    else:
        print "Bad magician!"
        output.write("Bad magician!\n")
input.close()
output.close()
