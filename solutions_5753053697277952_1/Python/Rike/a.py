file = open("C:\\Users\\Rike\\Documents\\GoogleCodeJam\\a.in", "r")
output = open("C:\\Users\\Rike\\Documents\\GoogleCodeJam\\output.txt", "w")

num_cases = int(file.readline())

for i in range(num_cases):
    output.write("Case #" + repr(i + 1) + ":")
    num_p = int(file.readline())
    num = file.readline().strip().split()

    l = []
    for i in range(num_p):  
        l.append([int(num[i]), "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i]])

    l.sort(reverse = True)
    #print(l)
    outfilestr = ''
    while(l[0][0] > l[1][0]):
        if l[0][0] > l[1][0] + 1:
                outfilestr = outfilestr + " " + l[0][1] + l[0][1]
                l[0][0] = l[0][0] - 2
        else:
            outfilestr = outfilestr + " " + l[0][1]
            l[0][0] = l[0][0] - 1
    for i in range(2, len(l)):
        while l[i][0]:
            if l[i][0] > 1:
                outfilestr = outfilestr + " " + l[i][1] + l[i][1]
                l[i][0] = l[i][0] - 2
            else:
                outfilestr = outfilestr + " " + l[i][1]
                l[i][0] = 0
    while(l[0][0]):
                outfilestr = outfilestr + " " + l[0][1] + l[1][1]
                l[0][0] = l[0][0] - 1
    

    #print(outfilestr)

    output.write(outfilestr + "\n")
output.close()
file.close()