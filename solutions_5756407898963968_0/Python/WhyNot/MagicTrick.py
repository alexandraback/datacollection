import re

def read_int(string):
    return int(re.match(r"\s*(\S+)\s*",string).group(1))
def read_4int(string):
    m=re.match(r"\s*(\S+)\s*(\S+)\s*(\S+)\s*(\S+)",string)
    return [int(m.group(1)),int(m.group(2)),int(m.group(3)),int(m.group(4))]

bad_mag = "Bad magician!"
vol_che = "Volunteer cheated!"

def solve():
    f = open("input","r")
    s = open("output","w")
    T = read_int(f.readline())
    for i in range(0,T):
        r1 = read_int(f.readline())
        matrix1 = []
        for j in range(0,4):
            matrix1.append(read_4int(f.readline()))
        r2 = read_int(f.readline())
        matrix2 = []
        for j in range(0,4):
            matrix2.append(read_4int(f.readline()))
        count=0
        for j in range(0,4):
            if matrix1[r1-1][j] in matrix2[r2-1]:
                count+=1
                res=matrix1[r1-1][j]
        if count == 0:
            s.write("Case #{0}: {1}\n".format((i+1),vol_che))
        elif count == 1:
            s.write("Case #{0}: {1}\n".format((i+1),res))
        else:
            s.write("Case #{0}: {1}\n".format((i+1),bad_mag))
    s.close()
    f.close()

solve()
