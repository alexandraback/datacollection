def compute(n, rows,rows2):
    print(n[0],n[1])
    print(rows[n[0]-1], rows2[n[1]-1])
    i=rows[n[0]-1]&rows2[n[1]-1]

    if i==set():
        return -1
    elif len(i)!=1:
        return -2
    else:
        return i.pop()


f=open("test2.in", "r")
n_test=int(f.readline())

for i in range(n_test):
    n_rows=list()
    rows=list()
    rows2=list()
    n_rows.append(int(f.readline().strip()))
    for j in range(4):
        rows.append(set(map(int, f.readline().split(" "))))

    n_rows.append(int(f.readline().strip()))
    for j in range(4):
        rows2.append(set(map(int, f.readline().split(" "))))
    result = compute(n_rows, rows,rows2)
    print(result)
    w=open("result.txt", "a")
    s="Case #"+str(i+1)+": "
    if result==-1:
        s+="Volunteer cheated!"
    elif result==-2:
        s+="Bad magician!"
    else:
        s+=str(result)
    w.write(s+"\n")
    w.close()
f.close()


