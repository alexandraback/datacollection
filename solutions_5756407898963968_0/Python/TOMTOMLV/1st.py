f = open("in.txt", "r")
fout = open("out.txt", "w")
t = int(f.readline())
for i in range(1, t+1):
    dic = {}
    for a in range(1,3):
        pos = int(f.readline())
        for j in range(1, 5):
            for val in [int(x) for x in f.readline().split()]:
                if j == pos:
                    if val in dic:
                        dic[val] += 1
                    else:
                        dic[val] = 1

    if len(dic) == 8:
        fout.write("Case #{:d}: Volunteer cheated!\n".format(i))
    elif len(dic) < 7:
        fout.write("Case #{:d}: Bad magician!\n".format(i))
    else:
        for val in dic.keys():
            if dic[val] == 2:
                fout.write("Case #{:d}: {:d}\n".format(i, val))