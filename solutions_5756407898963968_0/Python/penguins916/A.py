f = open("A.in")
num = int(f.readline())
output = ""
for n in range(num):
    row1 = int(f.readline())
    grid1 = [[] for x in range(4)]
    for i in range(4):
        grid1[i] = [int (x) for x in f.readline().strip().split(" ")]
    
    row2 = int(f.readline())
    grid2 = [[] for x in range(4)]
    for i in range(4):
        grid2[i] = [int (x) for x in f.readline().strip().split(" ")]


    s1 = set(grid1[row1 - 1])
    s2 = set(grid2[row2 - 1])

    res = s1.intersection(s2)
    output_val = None
    if len(res) == 1:
        output_val = str(list(res)[0])
    if len(res) > 1:
        output_val = "Bad magician!"
    if len(res) == 0:
        output_val = "Volunteer cheated!"

    output += "Case #"+str(n+1) + ": " + output_val +"\n"

f = open ("A.out", "w+")
f.write(output)
f.close()



