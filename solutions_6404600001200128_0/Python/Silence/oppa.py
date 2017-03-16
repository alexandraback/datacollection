__author__ = 'anton'

def A():
    file = open("input", "r")
    output = open("output", "w")
    lines = [tmp.strip().split(" ") for tmp in file.readlines()[2::2]]
    cnt = 1
    for line in lines:
        res = 0
        sp = 0
        for i in range(len(line) - 1):
            res += max(0, int(line[i]) - int(line[i + 1]))
            sp = max(sp, int(line[i]) - int(line[i + 1]))
        print sp
        tmp = 0
        for i in range(len(line) - 1):
            tmp += min(sp, int(line[i]))
        output.write("Case #" + str(cnt) + ": " + str(res) + " " + str(tmp) + "\n")
        cnt += 1
    file.close()
    output.close()

A()